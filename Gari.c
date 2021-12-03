#include <stdio.h>
#include <stdlib.h>
#include "Gari.h"

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

Contador *liberamem(Contador* h, Contador *aux, Contador *prim){
  if(prim->ct == 0){
    free(h);
		return aux;
  }
	else if(aux->ct == 0){
		h->prox = aux->prox;
    free(aux);
		return h;
	}
	else
		return Ct0(h->prox,aux->prox,prim);
}

void atualiza(void *x, int y){
  Contador*aux = lista;
  while (aux!=NULL){
      if(aux->endereco == x){
          aux->referencias += y;
      if(aux->referencias==0)
        lista = liberamem(lista,lista->prox,lita);
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
