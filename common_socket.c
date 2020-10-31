#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "common_socket.h"

int socket_create(socket_t *self) {
    self->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (self->socket == -1) {
        printf("No se pudo crear el socket");
    }
    return 0;
}

int socket_connect(socket_t *self, int port, char *ip) {
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    struct sockaddr *s_sock = (struct sockaddr *)&server;
    if (connect(self->socket,s_sock , sizeof(server)) < 0) {
        printf("Error conexion");
    }
    return 0;
}

int socket_bind(socket_t *self, int port) {
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr= INADDR_ANY;
    server.sin_port = htons(port);
    if (bind(self->socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("BINd failed");
    }
    return 0;
}

int socket_listen(socket_t *self) {
    listen(self->socket, 10);
    struct sockaddr_in client;
    struct sockaddr *c_sock = (struct sockaddr *)&client;
    socklen_t client_size = sizeof(client);
    self->new_socket =  accept(self->socket, c_sock,&client_size);
    return self->new_socket;
}

int socket_send(socket_t *self, const char* buffer, size_t lenght) {
    return send(self->socket, buffer, lenght, 0);
}

int socket_receive(socket_t *self, void *buffer, size_t lenght) {
    return recv(self->new_socket, buffer, lenght, 0);
}

int socket_close(socket_t *self) {
    return close(self->socket);
}
