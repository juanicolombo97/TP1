#include "common_cifrado.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void cifrado_create(cifrado_t *self, char *method, void *key) {
    self->method = method;                                  // Guardo el method recibido.
    self->key = key;
}

void cifrado_encriptar(cifrado_t *self, char* message, size_t *message_size) {
    cifrado_elegir(self, message, message_size, "encriptar");
}

void cifrado_desencriptar(cifrado_t *self, char* message, size_t *message_size){
    cifrado_elegir(self, message, message_size, "desencriptar");
}

void cifrado_elegir(cifrado_t *self, char* message, size_t *message_size,char* type){
    if (!strcmp(self->method, "cesar")) {                   // Me fijo si el metodo es el cesar y llamo a la funcion respectiva para cifrar.
        cifrado_cesar(self, message, message_size, type);
    } else if (!strcmp(self->method, "vigenere")) {         // Me fijo si el metodo es vigenere y llamo a la funcion respectiva para cifrar.
        cifrado_vigenere(self, message);
    } else if (!strcmp(self->method, "rc4")) {              // Me fijo si el metodo es rc4 y llamo a la funcion respectiva para cifrar.
        printf("rc44444444444");
    } else printf("Metodo incorrecto");
    
}

void cifrado_cesar(cifrado_t *self, char* message, size_t *message_size,char* type) {
    for (size_t i = 0; i < *message_size; i++) {
        if(!strcmp(type, "encriptar")){
            *message = ((*message + (*(int*)(self->key))) % 256);
        
        } else {
            *message = ((*message - (*(int*)(self->key))) % 256);
        }
        message++;        
    }
    
}

void cifrado_vigenere(cifrado_t *self, char* message) {

   printf("dqjhfwuehfuhwef");
}

void cifrado_destroy(cifrado_t *self) {
    //do nothing
}

