#define MAXCHAR 64
#define MAXMESSAGE 1024
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "server_socket.h"
#include "common_socket.h"
#include "common_cifrado.h"

void server_desifrar_mensaje(char* buf, char* method, void* key, int bytes_r) {
   cifrado_t cifrado;
   cifrado_create(&cifrado, method, key);
   cifrado_desencriptar(&cifrado, buf, bytes_r);
   fwrite(buf, 1, sizeof(buf), stdout);
}

void server_start(int p_port,char* p_method,void * p_key) {
   socket_t socket;
   socket_create(&socket);
   socket_bind(&socket, p_port);
   int received_socket = socket_listen(&socket);
   server_r(received_socket, socket, p_method, p_key);
}

void server_r(int socket_rec, socket_t socket, char* method, void* key) {
   int total_bytes_received = 0;
   bool valid_socket = true;
   while (total_bytes_received < MAXMESSAGE && valid_socket) {
      char *buf = (char*)calloc(MAXCHAR, sizeof(char));
      int bytes_recibidos = socket_receive(&socket,buf, socket_rec);
      if (bytes_recibidos <= 0) {
         valid_socket = false;
         free(buf);
         continue;
      }
      server_desifrar_mensaje(buf, method, key, bytes_recibidos);
      free(buf);
      total_bytes_received += bytes_recibidos;
   }   
}
