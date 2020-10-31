#ifndef __CLIENT_SOCKET_H__
#define __CLIENT_SOCKET_H__

#include "common_socket.h"
#include "common_cifrado.h"


// FUncion que inicia un socket, lo connecta, envia mensaje a un servidor y cierra el socket.
void client_start(int p_port,char* p_method,void * p_key, char* p_ip);

// Funcion que lee el archivo de entrada estandar  y lo encripta.
void client_send_message(socket_t socket,char* p_method, void* p_key);

// FUncion que recibe el mensaje encriptado y se lo envia a un servidor.
void client_enviar_mensaje_socket(socket_t socket, char* buffer,size_t bytes_read);

#endif
