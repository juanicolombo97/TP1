#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "client_socket.h"



void iniciar_client(char* argv[]) {
   long p_port = strtol(argv[2], NULL, 10);
   char *p_method = argv[3] + 9;
   void *p_key = argv[4] + 4;
   char *p_ip = argv[1];
   client_start(p_port, p_method, p_key, p_ip);
}

int main(int argc, char *argv[]) {
   if (argc < 3){
      return 0;
   }
   iniciar_client(argv);
   return(0);
}

