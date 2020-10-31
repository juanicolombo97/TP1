#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

void swap(int vector[], int i, int j) {

    int aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}


void prga(size_t message_size, int vector[], int vectorFinal[]) {
    int i = 0;
    int j = 0;
    for (int x = 0; x < message_size; x++) {
        i = ( i +1) % 256;
        j = (j + vector[i]) % 256;
        swap(vector, i, j);
        int t = (vector[i] + vector[j]) % 256;
        vectorFinal[x] = vector[t];
    }
}


void iniciar_vectores(int vector[], int vectorClave[], size_t key_size, void *key) {
    int contador = 0;
    for (int x = 0 ; x < 256; x++) {
        if (contador == key_size) {
            key -= contador;
            contador = 0;        
        }
        vector[x] = x;
        vectorClave[x] = *(int*)key;
        key++;
        contador++;
    }
}

void ksa(char *mensaje, size_t message_size, char *method, void *key) {
    int vector[256];
    int vectorClave[256];
    int vectorFinal[5];
    size_t key_size = strlen(key);
    iniciar_vectores(vector, vectorClave, key_size,key);
    int j =0;
    for (int i = 0; i < 256; i++) {
        j = (j + vector[i] + vectorClave[i]) % 256;
        swap(vector, i, j);
    }
    printf("INICIO PRGA\n");
    prga(message_size, vector, vectorFinal);
}

void iniciar(char *mensaje, size_t message_size, char *method, void *key) {
    printf("%s ", mensaje);
    printf("%s ", method);
    printf("%ld ", message_size);
    printf("%s\n", (char*)key);
    ksa(mensaje, message_size, method, key);
}


int main(int argc, char *argv[]) {

    char mensaje[] = "Pan";
    void *key = "queso";
    char *method ="rc4";
    size_t size = strlen(mensaje);
    iniciar(mensaje, size, method, key);
    return 0;
}
