#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "client_socket.h"

void client_start(int p_port,char* p_method,void * p_key, char* p_ip) {
    socket_t socket;
    socket_create(&socket);
    socket_connect(&socket, p_port, p_ip);
    client_send_message(socket, p_method, p_key);
    socket_close(&socket);
}

void client_send_message(socket_t socket,char* p_method, void* p_key) {
   cifrado_t cifrado;
   cifrado_create(&cifrado, p_method, p_key);
   while (!feof(stdin)) {
        char buffer[64];
        size_t bytes_read = fread(buffer, sizeof(char), 64, stdin);
        cifrado_encriptar(&cifrado, buffer, bytes_read);
        client_enviar_mensaje_socket(socket, buffer, bytes_read);       
    }
}

void client_enviar_mensaje_socket(socket_t socket, char* buffer,size_t bytes_read) {
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

