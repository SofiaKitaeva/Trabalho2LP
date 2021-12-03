#ifndef GARI_H_INCLUDED
#define GARI_H_INCLUDED

typedef struct Contador{
    void* endereco;
    int referencias;
    struct Contador* prox;
}contador;

void* InsereCont(size_t x);

void atualiza(void *x, int y);

void* malloc2(size_t tam);

void atrib2(int **x, int *y);

#endif // GARI_H_INCLUDED
