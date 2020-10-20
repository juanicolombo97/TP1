#ifndef __COMMON_SOCKET_H__
#define __COMMON_SOCKET_H__

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
typedef struct{
    int socket;
    int new_socket;
    struct sockaddr_in server;
    struct sockaddr_in client;
} socket_t;


int socket_create(socket_t *self, struct sockaddr_in server);

int socket_connect(socket_t *self);

int socket_send(socket_t *self, const char* buffer, size_t lenght);

int socket_bind_and_listen(socket_t *self);

int socket_receive(socket_t *self, void* buffer, size_t lenght);

int socket_shutdown(socket_t *self, int how);

int socket_close(socket_t *self);
#endif
 