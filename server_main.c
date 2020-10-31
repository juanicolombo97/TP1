#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_socket.h"
#include "common_cifrado.h"

void desifrar_mensaje(char* buf, char* method, void* key) {
   size_t bytes_recibidos = strlen(buf);
   cifrado_t cifrado;
   cifrado_create(&cifrado, method, key);
   cifrado_desencriptar(&cifrado, buf, bytes_recibidos);
   printf("%s", buf);
}

void socket_start(int p_port,char* p_method,void * p_key) {
   socket_t socket;
   socket_create(&socket);
   socket_bind(&socket, p_port);
   int received_socket = socket_listen(&socket);
   char buf[64];
   socket_receive(&socket,buf, received_socket);
   desifrar_mensaje(buf, p_method, p_key);
}
void iniciar_server(char* argv[]) {
   long p_port = strtol(argv[1], NULL, 10);
   char *p_method = argv[2] + 9;
   void *p_key = argv[3] + 4;
   socket_start(p_port, p_method, p_key);
}

int main(int argc, char *argv[]) {
   if (argc < 3){
      return 0;
   }
   iniciar_server(argv);
   return(0);
}

