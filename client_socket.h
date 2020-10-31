#ifndef __CLIENT_SOCKET_H__
#define __CLIENT_SOCKET_H__

#include "common_socket.h"
#include "common_cifrado.h"

void client_start(int p_port,char* p_method,void * p_key, char* p_ip);

void client_send_message(socket_t socket,char* p_method, void* p_key);

void client_enviar_mensaje_socket(socket_t socket, char* buffer,size_t bytes_read);

#endif
