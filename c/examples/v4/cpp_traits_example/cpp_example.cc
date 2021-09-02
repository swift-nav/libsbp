#include <iostream>
#include <tuple>
#include <cassert>

#include <libsbp/v4/navigation.h>
#include <libsbp/v4/imu.h>
#include <libsbp/v4/mag.h>
#include <libsbp/cpp/message_traits.h>

using process_msg_t = void (*)(sbp_msg_type_t msg_type, const sbp_msg_t &msg);

/* A class used for holding a number of sbp msg structures and, when requested,
 * sending them to a user defined process function */
template <typename... MessageTypes>
class MessageHolder {
 public:
  MessageHolder(process_msg_t process_fn) : process_fn_(process_fn) {}

  template <typename MessageType>
  void stage_message(MessageType msg) {
    std::get<MessageType>(messages_) = msg;
  }

  template <typename MessageType>
  void process_message(void) {
    MessageType &msg = std::get<MessageType>(messages_);
    sbp_msg_type_t msg_type = sbp::MessageTraits<MessageType>::id;
    process_fn_(msg_type, sbp::MessageTraits<MessageType>::to_sbp_msg(msg));
  }

  process_msg_t process_fn_;
  std::tuple<MessageTypes...> messages_; 
};

void process_message(sbp_msg_type_t msg_type, const sbp_msg_t &msg) {
  if (msg_type == SbpMsgGpsTime) {
    std::cout << "Got a GPS time with tow: " << msg.gps_time.tow << std::endl;
  } else if (msg_type == SbpMsgMagRaw) {
    std::cout << "Got a Mag RAW with mag_x: " << msg.mag_raw.mag_x << std::endl;
  } else if (msg_type == SbpMsgImuAux) {
    std::cout << "Got a IMU AUX with temp: " << msg.imu_aux.temp << std::endl;
  } else {
    assert("Unknown message");
  }
}

/* A super contrived example that shows how the sbp::MessageTraits class might
 * be useful, focusing on its use with templated utility classes.
 */
int main()
{
  MessageHolder<sbp_msg_gps_time_t, sbp_msg_mag_raw_t, sbp_msg_imu_aux_t> messageHolder(process_message);

  // Construct some structs with dummy data
  sbp_msg_gps_time_t time{.wn=1, .tow=1, .ns_residual=1, .flags=1};
  sbp_msg_mag_raw_t mag{.tow=2, .tow_f=2, .mag_x=2, .mag_y=2, .mag_z=2};
  sbp_msg_imu_aux_t aux{.imu_type=3, .temp=3, .imu_conf=3};

  messageHolder.stage_message<sbp_msg_gps_time_t>(time);
  messageHolder.stage_message<sbp_msg_mag_raw_t>(mag);
  messageHolder.stage_message<sbp_msg_imu_aux_t>(aux);

  messageHolder.process_message<sbp_msg_gps_time_t>();
  messageHolder.process_message<sbp_msg_mag_raw_t>();
  messageHolder.process_message<sbp_msg_imu_aux_t>();

  return 0;
}

