#include "common_cifrado.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void cifrado_create(cifrado_t *self, char *method, void *key) {
    self->method = method;                                  // Guardo el method recibido.
    self->key = key;
}

void cifrado_encriptar(cifrado_t *self) {
    if (!strcmp(self->method, "cesar")) {                   // Me fijo si el metodo es el cesar y llamo a la funcion para cifrar
        cifrado_cesar(self);
    } else if (!strcmp(self->method, "vigenere")) {         // Me fijo si el metodo es vigenere.
        cifrado_vigenere(self);
    } else if (!strcmp(self->method, "rc4")) {              // Me fijo si el metodo es rc4.
        printf("rc44444444444");
    } else printf("Metodo incorrecto");
    
}

void cifrado_cesar(cifrado_t *self) {
     printf("La clave es: %d", (*(int*)self->key));
}
void cifrado_vigenere(cifrado_t *self) {
    printf("%s", (char*)self->key); 
}

void cifrado_destroy(cifrado_t *self) {
    //do nothing
}

