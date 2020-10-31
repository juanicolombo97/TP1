#ifndef __COMMON_SOCKET_H__
#define __COMMON_SOCKET_H__


typedef struct{
    int socket;             // Almacena el socket creado.
    int new_socket;         // Almacena el socket recibido 
} socket_t;

// Funcion que crea un socket
int socket_create(socket_t *self);

// Funcion que conecta el socket a un puerto y ip
int socket_connect(socket_t *self, int port, char *ip);

// FUncion que envia un mensaje a un servidor.
int socket_send(socket_t *self, const char* buffer, size_t lenght);

// FUncion que  bindea un socket a un puerto determinado.
int socket_bind(socket_t *self, int port);

// FUncion que pone al socket en escuha para conecciones entrantes.
int socket_listen(socket_t *self);

// FUncion que recibe un mensaje de a bytes y los lee hasta recibir el mensaje completo.
int socket_receive(socket_t *self, void* buffer, size_t lenght);

// FUncion que apaga el socket.
int socket_shutdown(socket_t *self, int how);

// Funcion que cierra el socket
int socket_close(socket_t *self);

#endif
