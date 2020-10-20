#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "common_socket.h"
#include "common_cifrado.h"

void enviar_mensaje_socket(socket_t socket, char* buffer,size_t bytes_read) {
   int bytes_sent = 0;
   bool valid_socket = true;
   while (bytes_sent < bytes_read && valid_socket) {
      int bytes_leidos = socket_send(&socket, buffer, bytes_read);
      if (bytes_leidos <= 0) {
         valid_socket = false;
      } else {
         bytes_sent += bytes_leidos;
      }
   }
}  

void send_message(socket_t socket,char* p_method, void* p_key) {
   cifrado_t cifrado;
   cifrado_create(&cifrado, p_method, p_key);
   while (!feof(stdin)) {
        char buffer[64];
        size_t bytes_read = fread(buffer, sizeof(char), 64, stdin);
        cifrado_encriptar(&cifrado, buffer, &bytes_read);
        enviar_mensaje_socket(socket, buffer, bytes_read);       
    }
}

void socket_start(int p_port,char* p_method,void * p_key, char* p_ip) {
   struct sockaddr_in server;
   server.sin_addr.s_addr = inet_addr(p_ip);
   server.sin_family = AF_INET;
   server.sin_port = htons(p_port);
   socket_t socket;
   socket_create(&socket,server);
   socket_connect(&socket);
   send_message(socket, p_method, p_key);
   socket_close(&socket);
}

void iniciar_server(char* argv[]) {
   long p_port = strtol(argv[2], NULL, 10);
   char *p_method = argv[3] + 9;
   void *p_key = argv[4] + 4;
   char *p_ip = argv[1];
   socket_start(p_port, p_method, p_key, p_ip);
}

int main(int argc, char *argv[]) {
   if(argc < 3){
      return 0;
   }
   iniciar_server(argv);
   return(0);
}

