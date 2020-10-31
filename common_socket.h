#ifndef __COMMON_SOCKET_H__
#define __COMMON_SOCKET_H__


typedef struct{
    int socket;
    int new_socket;
} socket_t;


int socket_create(socket_t *self);

int socket_connect(socket_t *self, int port, char *ip);

int socket_send(socket_t *self, const char* buffer, size_t lenght);

int socket_bind(socket_t *self, int port);

int socket_listen(socket_t *self);

int socket_receive(socket_t *self, void* buffer, size_t lenght);

int socket_shutdown(socket_t *self, int how);

int socket_close(socket_t *self);

#endif
