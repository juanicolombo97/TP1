#ifndef __COMMON_CIFRADO_H__
#define __COMMON_CIFRADO_H__


typedef struct {
    char *method; // Reservo un char de 8 bytes para el metodo.
    void *key;
} cifrado_t;

// ALmacena el method y key.
void cifrado_create(cifrado_t *self, char *method, void *key);

// FUncion que se llama cuando se desea encriptar y comienza el encriptado.
void cifrado_encriptar(cifrado_t *self, char* m, size_t message_size);

// FUncion que se llama cuando se desea desencriptar y comienza el 
// desencriptado.
void cifrado_desencriptar(cifrado_t *self, char* m, size_t message_size);

// ELige el cifrado segun el method previamente almacenado.
void cifrado_elegir(cifrado_t *self, char* m, size_t s,  void(*f)(char*, int));

// Funcion que sifra un mensaje con el cifrado cesar.
void cifrado_cesar(cifrado_t *self, char* m, size_t s, void(*f)(char*, int));


// Funcion que sifra un mensaje con el cifrado vigenere.
void cifrado_v(cifrado_t *self, char* m, size_t s, void(*f)(char*, int));


// Funcion que sifra un mensaje con el cifrado rc4.
void cifrado_rc4(cifrado_t *self, size_t s, char *m,  void(*f)(char*, int));

// FUncion que suma a cada byte del mensaje, cierto valor dependiendo del method
void cifrado_proceso_encriptar(char* message, int key);

// FUncion que resta a cada byte del mensaje, cierto valor dependiendo del
// method
void cifrado_proceso_desencriptar(char* message, int key);

// Funcion que realiza el ksa del metodo rc4
void cifrado_rc4_ksa(cifrado_t *self,int vector[], int v[]);

// FUncion que inicializa los vetores para empezar rc4.
void cifrado_rc4_inicializar_vectores(cifrado_t *self,int vector[], int v[]);

// FUncion que recibe dos vectores e intercambia sus valores segun los indices
// recibidos.
void cifrado_rc4_swap(cifrado_t *self, int vector[], int i, int j);

// FUncion que realiza el prga del metodo rc4
void cifrado_rc4_prga(cifrado_t *self, int v[], size_t s, char *m, int r[]);

#endif
