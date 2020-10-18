#include <stdio.h>
#include "common_cifrado.h"
int main() {

   char method[] = "rc4";
   int key = 1;
   char key2[] = "queso"; 
   size_t tamanio = 3;
   char palabra[] = "Pan";
   void *key1 = &key2;
   cifrado_t cifrado;
   cifrado_create(&cifrado, method, key1);
   printf("Antes de encriptar %s\n", palabra);
   cifrado_encriptar(&cifrado, palabra, &tamanio);
   printf("Despues de encriptar %s\n", palabra);
   cifrado_desencriptar(&cifrado, palabra, &tamanio);
  printf("Despues de Desencriptar: %s\n", palabra);
   return 0;
}