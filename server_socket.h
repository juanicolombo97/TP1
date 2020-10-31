#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__

#include "common_socket.h"
#include "common_cifrado.h"

// Funcion que inicializa un servidor.
void server_start(int p_port,char* p_method,void * p_key);

// Funcion que recibe un mensaje y lo desencripta segun el metodo y clave.
void server_desifrar_mensaje(char* buf, char* method, void* key, int bytes_recibidos);

// Funcion que lee los mensajes recibidos de un cliente.
void server_r(int socket_rec, socket_t socket, char* method, void* key);

#endif
