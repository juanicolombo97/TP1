#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server_socket.h"

// FUncion que inicializa el server_socket
void iniciar_server(char* argv[]) {
   long p_port = strtol(argv[1], NULL, 10);
   char *p_method = argv[2] + 9;
   void *p_key = argv[3] + 4;
   server_start(p_port, p_method, p_key);
}

int main(int argc, char *argv[]) {
   if (argc < 3){
      return 0;
   }
   iniciar_server(argv);
   return(0);
}

