#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "common_cifrado.h"
#define VECTORLEN 256
#define MAXMES 64

void cifrado_create(cifrado_t *self, char *method, void *key) {
    self->method = method;
    self->key = key;
}

void cifrado_encriptar(cifrado_t *self, char* message, size_t message_size) {
    cifrado_elegir(self, message, message_size, cifrado_proceso_encriptar);
}

void cifrado_desencriptar(cifrado_t *self, char* message, size_t message_size){
    cifrado_elegir(self, message, message_size, cifrado_proceso_desencriptar);
}

void cifrado_elegir(cifrado_t *self, char* m, size_t s,  void(*f)(char*, int)){
    if (!strcmp(self->method, "cesar")) {                  
        cifrado_cesar(self, m, s, f);
    } else if (!strcmp(self->method, "vigenere")) {         
        cifrado_v(self, m, s, f);
    } else if (!strcmp(self->method, "rc4")) {              
        cifrado_rc4(self,s, m, f);
    }
}

void cifrado_cesar(cifrado_t *self, char* m, size_t s,  void(*f)(char*, int)) {
    for (size_t i = 0; i < s; i++) {
        f(m,*(int*)(self->key));
        m++;        
    }   
}

void cifrado_proceso_encriptar(char* message, int key) {
    *message = ((*message + key) % VECTORLEN);
}

void cifrado_proceso_desencriptar(char* message, int key) {
    *message = ((*message - key) % VECTORLEN);
}

void cifrado_v(cifrado_t *self, char* m, size_t s, void(*f)(char*, int)) {
    int key_size = strlen(self->key);
    char *key_aux = self->key;
    for (size_t i = 0; i < s; i++) {
        if (!i % key_size) {
            key_aux-= key_size;
        }     
        f(m, *(int*)key_aux);
        key_aux++;
        m++;
    }
}

void cifrado_rc4(cifrado_t *self, size_t s, char *m,  void(*f)(char*, int)) {
    int vector[VECTORLEN], vectorClave[VECTORLEN], resultado[MAXMES];
    cifrado_rc4_inicializar_vectores(self, vector, vectorClave);
    cifrado_rc4_ksa(self, vector, vectorClave);
    cifrado_rc4_prga(self, vector, s, m, resultado);
    for (int x = 0; x < s; x++) {
        f(m,resultado[x]);
        m++;
    }
}

void cifrado_rc4_inicializar_vectores(cifrado_t *self,int vector[], int vClave[]){
    size_t tamanio = strlen(self->key);
    int contador = 0;
    for (int i = 0; i < VECTORLEN; i++) {
        if (tamanio == contador) {
            contador = 0;
        }
        vector[i] = i;
        vClave[i] = *(char*)(self->key + contador);
        contador++;
    } 
}

void cifrado_rc4_ksa(cifrado_t *self, int vector[], int vClave[]){
    int i = 0;
    int j = 0;
    for (i = 0; i < VECTORLEN; i++) {
        int key_char = vClave[i];
        j = (j + vector[i] + key_char) % VECTORLEN;
        cifrado_rc4_swap(self, vector, i , j);
    }
}

void cifrado_rc4_swap(cifrado_t *self, int vector[], int i, int j) {
    int aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}

void cifrado_rc4_prga(cifrado_t *self, int v[], size_t s, char *m, int r[]) {
    int i = 0;
    int j = 0;
    for (int x = 0; x < s; x++) {
        i = (i + 1) % VECTORLEN;
        j = (j + v[j]) % VECTORLEN;
        cifrado_rc4_swap(self, v, i, j);
        r[x]=v[(v[i] + v[j]) % VECTORLEN];
    }
}

