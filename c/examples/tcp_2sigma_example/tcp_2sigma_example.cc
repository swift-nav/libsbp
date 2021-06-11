/*
 * Example demonstrating how to parse SBP data from a TCP port and compute the
 * ellipse representing the 2 sigma confidence level.
 *
 * Requires libsbp (https://github.com/swift-nav/libsbp) and Eigen 3 (https://eigen.tuxfamily.org/).
 * Eigen 3 is provided by the libeigen3-dev package on Debian-like Linux distributions.
 *
 * Compile using:
 * g++ tcp_2sigma_example.cc -I ${LIBSBP}/c/include/ -L ${LIBSBP}/c/build/src/ -lsbp
 *
 * If compiled with -DSHOW_PLOT then the ellipses will be graphically displayed.
 * This functionality requires OpenCV3 (https://opencv.org/) which is provided
 * by the libopencv-dev package on Debian-like Linux distributions.
 *
 * Compile using:
 * g++ tcp_2sigma_example.cc -DSHOW_PLOT -I ${LIBSBP}/c/include/ -L ${LIBSBP}/c/build/src/ -lsbp -lopencv_core -lopencv_imgproc -lopencv_highgui
 *
 * Originally adapted from https://github.com/swift-nav/libsbp/blob/master/c/example/tcp_example/tcp_example.c
 */

#ifndef SHOW_PLOT
#define SHOW_PLOT 0
#endif /* SHOW_PLOT */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <cmath>
#include <vector>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigenvalues>
#if SHOW_PLOT
#include <opencv2/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#endif /* SHOW_PLOT */

#include <libsbp/sbp.h>
#include <libsbp/legacy/navigation.h>

// width and height of the plot window in pixels
#define SIZE_PIXELS 300
// width and height of the plot window in metres
#define SIZE_METRES 10


void usage(const char* prog_name) {
    fprintf(stderr, "usage: %s [-a address -p port]\n", prog_name);
}


int open_socket(const char* host, int port) {
    struct sockaddr_in server;
    int fd = socket(AF_INET , SOCK_STREAM , 0);

    if(fd < 0) {
        fprintf(stderr, "Could not create socket\n");
        return -1;
    }

    memset(&server, '0', sizeof(server));
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if(connect(fd, (struct sockaddr *)&server , sizeof(server)) < 0) {
        fprintf(stderr, "Connection error\n");
        close(fd);
        return -1;
    }

    return fd;
}


/*
 * Calculate the half major axis length, half minor axis length and rotation
 * angle for an error ellipse corresponding to the confidence interval
 * 'chi_squared' with the covariance matrix 'covmat'.
 *
 * Assumes normal distribution.
 *
 * See https://www.visiondummy.com/2014/04/draw-error-ellipse-representing-covariance-matrix/
 * for an explanation of the algorithm.
 */
bool get_ellipse_parameters(const double& chi_squared, const Eigen::Matrix2d& covmat, double& half_major_axis, double& half_minor_axis, double& angle) {
    std::vector<std::tuple<double, Eigen::Vector2d>> eigen_vectors_and_values;

    // compute eigenvalues and eigenvectors
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> eigensolver(covmat);
    if(eigensolver.info() != Eigen::Success) {
        return false;
    }

    // copy results into eigen_vectors_and_values
    Eigen::Vector2d eigen_values = eigensolver.eigenvalues();
    Eigen::Matrix2d eigen_vectors = eigensolver.eigenvectors();
    for(int i = 0; i < eigen_values.size(); i++) {
        std::tuple<double, Eigen::Vector2d> vec_and_val(eigen_values[i], eigen_vectors.col(i));
        eigen_vectors_and_values.push_back(vec_and_val);
    }

    // sort eigen_vectors_and_values in descending order of eigenvalue
    std::sort(eigen_vectors_and_values.begin(), eigen_vectors_and_values.end(),
        [&](const std::tuple<double, Eigen::Vector2d>& a, const std::tuple<double, Eigen::Vector2d>& b) -> bool{
            return std::get<double>(b) < std::get<double>(a);
    });

    // calculate the angle between the largest eigenvector and the x-axis
    Eigen::Vector2d largest_eigenvector = std::get<Eigen::Vector2d>(eigen_vectors_and_values[0]);
    angle = atan2(largest_eigenvector[1], largest_eigenvector[0]);

    // shift the angle to the [0, 2pi] interval instead of [-pi, pi]
    if(angle < 0) angle += 2 * M_PI;

    // convert to degrees
    angle = 180. * angle / M_PI;

    // calculate the length of the minor and major axes
    half_major_axis = chi_squared * sqrt(std::get<double>(eigen_vectors_and_values[0]));
    half_minor_axis = chi_squared * sqrt(std::get<double>(eigen_vectors_and_values[1]));

    return true;
}


#if SHOW_PLOT
void plot_ellipse(const double& half_major_axis, const double& half_minor_axis, const double& angle) {
    // the mean is nominally at the origin (i.e. reported lat/lon) but
    // for graphing purposes we shift it to the middle of our plot window
    cv::Point2f mean(SIZE_PIXELS/2, SIZE_PIXELS/2);

    // scale factor from metres to pixels
    double scale = SIZE_PIXELS / SIZE_METRES;

    // negative angle because OpenCV defines the angle clockwise instead of
    // anti-clockwise
    cv::RotatedRect ellipse(mean, cv::Size2f(half_major_axis * scale, half_minor_axis * scale), -angle);

    //Show the result
    cv::Mat visualizeimage(SIZE_PIXELS, SIZE_PIXELS, CV_8UC1, cv::Scalar::all(0));
    cv::ellipse(visualizeimage, ellipse, cv::Scalar::all(255), 2);
    cv::imshow("2 Sigma Ellipse", visualizeimage);
}
#endif /* SHOW_PLOT */


void pos_llh_cov_callback(u16 /*sender_id*/, u8 /*len*/, u8 msg[], void* /*context*/) {
    const msg_pos_llh_cov_t* msg_pos_llh_cov = (msg_pos_llh_cov_t*)msg;
    if((msg_pos_llh_cov->flags & 0x7) != 0) {
        printf("TOW %u ms, Lat: %.15f deg, Lon: %.15f deg, Hgt: %.15f m\n", msg_pos_llh_cov->tow, msg_pos_llh_cov->lat, msg_pos_llh_cov->lon, msg_pos_llh_cov->height);

        // north/east submatrix
        Eigen::Matrix2d covmat;
        covmat << msg_pos_llh_cov->cov_n_n, msg_pos_llh_cov->cov_n_e, msg_pos_llh_cov->cov_n_e, msg_pos_llh_cov->cov_e_e;

        /*
         * Starling computes horizontal accuracy (as reported in
         * MSG_POS_LLH.h_accuracy) as the square root of the L2 norm of
         * the north/east submatrix.  So the naive (but inaccurate) approach
         * is just to double it to get the worst-case 2 \Sigma value
         */
        double hrms = sqrt(covmat.operatorNorm()) * 2.;
        printf("\t2DRMS (naive): %.3f m -> area %.3f m^2\n", hrms, M_PI * hrms * hrms);

        /*
         * A more accurate approach is to compute the error ellipse corresponding to
         * the 95% confidence interval
         */
        double half_major_axis, half_minor_axis, angle;

        /*
         * From https://people.richland.edu/james/lecture/m170/tbl-chi.html
         * 95% confidence interval => area to the right = 0.05, 2 degrees of freedom =>
         * sqrt(5.991) = 2.4477
         *
         * For 99% confidence interval this would be sqrt(9.210) = 3.0348
         */
        const double chi_squared = 2.4477;

        if(get_ellipse_parameters(chi_squared, covmat, half_major_axis, half_minor_axis, angle)) {
            double area = M_PI * half_major_axis * half_minor_axis;
            printf("\tEllipse parameters: half major axis %g m, half minor axis %g m, angle %g deg -> area %.3f m^2\n", half_major_axis, half_minor_axis, angle, area);

#if SHOW_PLOT
            plot_ellipse(half_major_axis, half_minor_axis, angle);
#endif /* SHOW_PLOT */
        }
    } else {
        printf("No fix\n");
    }
}


s32 socket_read(u8* buff, u32 n, void* context) {
    int fd = *(int*)context;
    return read(fd, buff, n);
}


int main(int argc, char* const argv[]) {
    int opt;
    char* host = NULL;
    char* port = NULL;
    sbp_state_t sbp_state;
    sbp_msg_callbacks_node_t callback_node[1]; // note: one node is required per callback
    int fd;

    if(argc <= 2) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    while((opt = getopt(argc, argv, "a:p:")) != -1) {
        switch (opt) {
            case 'a':
                host = optarg;
                break;
            case 'p':
                port = optarg;
                break;
            case 'h':
                usage(argv[0]);
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    if(!host || !port) {
        fprintf(stderr, "Please supply the address and port of the SBP data stream!\n");
        exit(EXIT_FAILURE);
    }

    fd = open_socket(host, atoi(port));
    if(fd < 0) {
        return EXIT_FAILURE;
    }

#if SHOW_PLOT
    cv::namedWindow("2 Sigma Ellipse");
    cv::startWindowThread();
#endif /* SHOW_PLOT */

    sbp_state_init(&sbp_state);
    sbp_state_set_io_context(&sbp_state, (void*)&fd);
    sbp_payload_callback_register(&sbp_state, SBP_MSG_POS_LLH_COV, &pos_llh_cov_callback, NULL, &callback_node[0]);

    while(1) {
        switch(sbp_process(&sbp_state, &socket_read)) {
            case SBP_OK:
            case SBP_OK_CALLBACK_EXECUTED:
            case SBP_OK_CALLBACK_UNDEFINED:
                break;
            case SBP_CRC_ERROR:
                printf("CRC Error\n");
                break;
        }
    }

    close(fd);
    return EXIT_SUCCESS;
}
