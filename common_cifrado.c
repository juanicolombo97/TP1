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
    cifrado_elegir(self, message, message_size, cifrado_proceso_encriptar);
}

void cifrado_desencriptar(cifrado_t *self, char* message, size_t *message_size){
    cifrado_elegir(self, message, message_size, cifrado_proceso_desencriptar);
}

void cifrado_elegir(cifrado_t *self, char* message, size_t *message_size,  void(*f)(char*, int)){
    if (!strcmp(self->method, "cesar")) {                   // Me fijo si el metodo es el cesar y llamo a la funcion respectiva para cifrar.
        cifrado_cesar(self, message, message_size, f);
    } else if (!strcmp(self->method, "vigenere")) {         // Me fijo si el metodo es vigenere y llamo a la funcion respectiva para cifrar.
        cifrado_vigenere(self, message, message_size, f);
    } else if (!strcmp(self->method, "rc4")) {              // Me fijo si el metodo es rc4 y llamo a la funcion respectiva para cifrar.
        printf("rc44444444444");
    } else printf("Metodo incorrecto");
    
}

void cifrado_cesar(cifrado_t *self, char* message, size_t *message_size,  void(*f)(char*, int)) {
    for (size_t i = 0; i < *message_size; i++) {
        f(message,*(int*)(self->key));
        message++;        
    }
    
}

void cifrado_proceso_encriptar(char* message, int key) {
    *message = (*message + key ) % 256;
}

void cifrado_proceso_desencriptar(char* message, int key) {
    *message = (*message - key ) % 256;
}

void cifrado_vigenere(cifrado_t *self, char* message, size_t *message_size, void(*f)(char*, int)) {
    int key_size = strlen(self->key);
    char *key_aux = self->key;
    for (size_t i = 0; i < *message_size; i++) {
        if (key_size == i) {
            key_aux -= key_size;
        }
        int ascii_value = *key_aux;
        f(message, ascii_value);
        key_aux++;
        message++;
    }
}

void cifrado_destroy(cifrado_t *self) {
    //do nothing
}

