#include "common_socket.h"


int socket_create(socket_t *self, struct sockaddr_in server) {
    self->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (self->socket == -1) {
        printf("No se pudo crear el socket");
    }
    self->server = server;
    return 0;
}

int socket_connect(socket_t *self) {
    if (connect(self->socket, (struct sockaddr *)&self->server, sizeof(self->server)) < 0) {
        printf("Error conexion");
    }
    return 0;
}

int socket_bind_and_listen(socket_t *self) {
   if( bind(self->socket,(struct sockaddr *)&self->server , sizeof(self->server)) < 0) {
       printf("BINd failed");
   }
   listen(self->socket, 10);    
   socklen_t client_size = sizeof(self->client);
   return accept(self->socket, (struct sockaddr *)&self->client,&client_size);

}

int socket_send(socket_t *self, const char* buffer, size_t lenght) {
    return send(self->socket, buffer, lenght, 0);
}

int socket_receive(socket_t *self, void *buffer, size_t lenght) {
    return recv(self->socket, buffer, 64, 0);
}

int socket_shutdown(socket_t *self, int how) {
    return shutdown(self->socket, how);
}

int socket_close(socket_t *self) {
    return close(self->socket);
}