#ifndef __COMMON_CIFRADO_H__
#define __COMMON_CIFRADO_H__

#include <string.h>
#include <stdio.h>


typedef struct {
    char *method; // Reservo un char de 8 bytes para el metodo.
    void *key;
} cifrado_t;


void cifrado_create(cifrado_t *self, char *method, void *key);

void cifrado_encriptar(cifrado_t *self);

void cifrado_cesar(cifrado_t *self);

void cifrado_vigenere(cifrado_t *self);

void cifrado_destroy(cifrado_t *self);


#endif
 