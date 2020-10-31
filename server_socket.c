#define MAXCHAR 64
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "server_socket.h"
#include "common_socket.h"
#include "common_cifrado.h"

void server_desifrar_mensaje(char* buf, char* method, void* key, int bytes_recibidos) {
   cifrado_t cifrado;
   cifrado_create(&cifrado, method, key);
   cifrado_desencriptar(&cifrado, buf, bytes_recibidos);
   fwrite(buf, 1, sizeof(buf), stdout);

}

void server_start(int p_port,char* p_method,void * p_key) {
   socket_t socket;
   socket_create(&socket);
   socket_bind(&socket, p_port);
   int received_socket = socket_listen(&socket);
   char *buf = (char*) calloc(MAXCHAR, sizeof(buf));
   int bytes_recibidos = socket_receive(&socket,buf, received_socket);
   server_desifrar_mensaje(buf, p_method, p_key, bytes_recibidos);
   free(buf);
}
