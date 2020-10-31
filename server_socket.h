#ifndef __SERVER_SOCKET_H__
#define __SERVER_SOCKET_H__

#include "common_socket.h"
#include "common_cifrado.h"


void server_start(int p_port,char* p_method,void * p_key);

void server_desifrar_mensaje(char* buf, char* method, void* key);

#endif
