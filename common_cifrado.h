#ifndef __COMMON_CIFRADO_H__
#define __COMMON_CIFRADO_H__


typedef struct {
    char *method; // Reservo un char de 8 bytes para el metodo.
    void *key;
} cifrado_t;


void cifrado_create(cifrado_t *self, char *method, void *key);

void cifrado_encriptar(cifrado_t *self, char* m, size_t message_size);

void cifrado_desencriptar(cifrado_t *self, char* m, size_t message_size);

void cifrado_elegir(cifrado_t *self, char* m, size_t s,  void(*f)(char*, int));

void cifrado_cesar(cifrado_t *self, char* m, size_t s, void(*f)(char*, int));

void cifrado_v(cifrado_t *self, char* m, size_t s, void(*f)(char*, int));

void cifrado_rc4(cifrado_t *self, size_t s, char *m,  void(*f)(char*, int));

void cifrado_proceso_encriptar(char* message, int key);

void cifrado_proceso_desencriptar(char* message, int key);

void cifrado_rc4_ksa(cifrado_t *self,int vector[], int v[]);

void cifrado_rc4_inicializar_vectores(cifrado_t *self,int vector[], int v[]);

void cifrado_rc4_swap(cifrado_t *self, int vector[], int i, int j);

void cifrado_rc4_prga(cifrado_t *self, int v[], size_t s, char *m, int r[]);

void cifrado_destroy(cifrado_t *self);

#endif
