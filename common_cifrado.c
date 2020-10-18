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
        cifrado_rc4(self);
    };
}

void cifrado_cesar(cifrado_t *self, char* message, size_t *message_size,  void(*f)(char*, int)) {
    for (size_t i = 0; i < *message_size; i++) {
        f(message,*(int*)(self->key));
        message++;        
    }
    
}

void cifrado_proceso_encriptar(char* message, int key) {
    *message = ((*message + key ) % 256);
}

void cifrado_proceso_desencriptar(char* message, int key) {
    *message = ((*message - key ) % 256);
}

void cifrado_vigenere(cifrado_t *self, char* message, size_t *message_size, void(*f)(char*, int)) {
    int key_size = strlen(self->key);
    char *key_aux = self->key;
    for (size_t i = 0; i < *message_size; i++) {
        if (!i % key_size) {
            key_aux-= key_size;
        }     
        f(message, *(int*)key_aux);
        key_aux++;
        message++;
    }
}


void cifrado_rc4(cifrado_t *self) {
    int vector[256];
    char vector_key[256];
    int key_size = strlen(self->key);
    cifrado_rc4_inicializar_vectores(self, vector);
    cifrado_rc4_ksa(self, vector);
}

void cifrado_rc4_inicializar_vectores(cifrado_t *self,int vector[]){
    for (int i = 0; i < 256; i++) {
        vector[i] = i;
    };
    
}

void cifrado_rc4_ksa(cifrado_t *self, int vector[]){
    int i, j=0;
    for (i = 0; i < 256; i++) {
        int key_char = *(char*)( self->key + (i % 5));
        printf("%d\n", key_char);
        j = (j + vector[i] + *((int*)self->key +  i )) % 256;
       
    }
}

void cifrado_rc4_swap(cifrado_t *self, int vector[], int i, int j) {
    int aux = vector[i];
    printf("%d", aux);
    vector[i] = vector[j];
    vector[j] = aux;
}

void cifrado_rc4_prga(cifrado_t *self, int vector[]) {

}

void cifrado_destroy(cifrado_t *self) {
    //do nothing
}

