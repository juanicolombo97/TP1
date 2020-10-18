#include <stdio.h>
#include "common_cifrado.h"
int main() {

   char method[] = "vigenere";
   int key = 5;
   char key2[] = "SecureKey"; 
   size_t tamanio = 14;
   char palabra[] = "Secure messege";
   void *key1 = &key2;
   cifrado_t cifrado;
   cifrado_create(&cifrado, method, key1);
  // printf("Antes de encriptar %s\n", palabra);
   cifrado_encriptar(&cifrado, palabra, &tamanio);
  // printf("Despues de encriptar %s\n", palabra);
  // cifrado_desencriptar(&cifrado, palabra, &tamanio);
  // printf("Despues de Desencriptar: %s\n", palabra);
   return 0;
}