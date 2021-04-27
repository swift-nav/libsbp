#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <libsbp/sbp.h>
#include <libsbp/system.h>

char *tcp_ip_addr = NULL;
char *tcp_ip_port = NULL;
static sbp_msg_callbacks_node_t heartbeat_callback_node;
int socket_desc = -1;

void usage(char *prog_name) {
  fprintf(stderr, "usage: %s [-a address -p port]\n", prog_name);
}

void setup_socket()
{
  struct sockaddr_in server;
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1)
  {
    fprintf(stderr, "Could not create socket\n");
  }

  memset(&server, '0', sizeof(server));
  server.sin_addr.s_addr = inet_addr(tcp_ip_addr);
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(tcp_ip_port));

  if (connect(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0)
  {
    fprintf(stderr, "Connection error\n");
  }
}

void close_socket()
{
  close(socket_desc);
}

void heartbeat_callback(u16 sender_id, u8 len, u8 msg[], void *context)
{
  (void)sender_id, (void)len, (void)msg, (void)context;
  fprintf(stdout, "%s\n", __FUNCTION__);
}

s32 socket_read(u8 *buff, u32 n, void *context)
{
  (void)context;
  s32 result;

  result = read(socket_desc, buff, n);
  return result;
}

int main(int argc, char **argv)
{
  int opt;
  int result = 0;
  sbp_state_t s;

  if (argc <= 2) {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  while ((opt = getopt(argc, argv, "a:p:")) != -1) {
    switch (opt) {
      case 'a':
        tcp_ip_addr = (char *)calloc(strlen(optarg) + 1, sizeof(char));
        if (!tcp_ip_addr) {
          fprintf(stderr, "Cannot allocate memory!\n");
          exit(EXIT_FAILURE);
        }
        strcpy(tcp_ip_addr, optarg);
        break;
      case 'p':
        tcp_ip_port = (char *)calloc(strlen(optarg) + 1, sizeof(char));
        if (!tcp_ip_port) {
          fprintf(stderr, "Cannot allocate memory!\n");
          exit(EXIT_FAILURE);
        }
        strcpy(tcp_ip_port, optarg);
        break;
      case 'h':
        usage(argv[0]);
        exit(EXIT_FAILURE);
      default:
        break;
    }
  }

  if ((!tcp_ip_addr) || (!tcp_ip_port)) {
    fprintf(stderr, "Please supply the address and port of the SBP data stream!\n");
    exit(EXIT_FAILURE);
  }

  setup_socket();
  sbp_state_init(&s);
  sbp_register_callback(&s, SBP_MSG_HEARTBEAT, &heartbeat_callback, NULL,
                        &heartbeat_callback_node);

  while(1) {
    sbp_process(&s, &socket_read);
  }

  close_socket();
  free(tcp_ip_addr);
  free(tcp_ip_port);
  return result;
}
