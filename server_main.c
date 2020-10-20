#include <stdio.h>
#include <stdlib.h>
#include "common_socket.h"
#include "common_cifrado.h"

void socket_start(int p_port,char* p_method,void * p_key) {
    
    socket_t socket;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr= INADDR_ANY;
    server.sin_port = htons(p_port);
    socket_create(&socket, server);
    socket_bind_and_listen(&socket);
}
void iniciar_server(char* argv[]) {
   long p_port = strtol(argv[1], NULL, 10);
   char *p_method = argv[2] + 9;
   void *p_key = argv[3] + 4;
   socket_start(p_port, p_method, p_key);
}

int main(int argc, char *argv[]) {
   if(argc < 3){
      return 0;
   }
   iniciar_server(argv);
   return(0);
}
