#include <stdio.h>
#include "common_cifrado.h"
int main() {

   char method[] = "vigenere";
   int key = 3;
   char juan[] = "juanpa";
   void *key1 = &juan;
   cifrado_t cifrado;
   cifrado_create(&cifrado, method, key1);
   cifrado_encriptar(&cifrado);

   return 0;
}