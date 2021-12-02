#include <stdio.h>
#include <stdlib.h>

typedef struct Contador{
    void* endereco;
    int referencias;
    struct Contador* prox;
}contador;

contador* lista = NULL;

void* InsereCont(size_t x){
    contador* novo = (contador*) malloc(sizeof(contador));
    novo->endereco=malloc(x);
    novo->referencias=1;
    novo->prox==NULL;
    if(lista->prox==NULL)
        lista->prox=novo;
    else{
        contador* aux = (contador*) malloc(sizeof(contador));
        aux=lista->prox;
        while(aux!=NULL)
            aux=aux->prox;
        aux->prox=novo;
    }

}

void atualiza(void *locala, int x){
  Contador*aux = lista;
  while (aux!=NULL){
      if(aux->endereco == locala){
          aux->referencias = aux->ct+x;
      if(aux->ct==0)
        lista = Ct0(heap,heap->prox,heap);
      break;}
    aux = aux->prox;
  }
}

void* malloc2(size_t tam){

    void* x = malloc(tam);

    return x;
}

void atrib2(int **x, int *y){
    if(*a!=NULL){
      atualiza(*x,-1);
      if(b!=NULL)
          atualiza(y,1);
    }
    *a=b;
}
