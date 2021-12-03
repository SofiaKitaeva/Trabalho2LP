#include <stdio.h>
#include <stdlib.h>
#include "Gari.h"

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

contador *liberamem(contador* h, contador *aux, contador *prim){
  if(prim->referencias == 0){
    free(h);
		return aux;
  }
	else if(aux->referencias == 0){
		h->prox = aux->prox;
    free(aux);
		return h;
	}
	else
		return liberamem(h->prox,aux->prox,prim);
}

void atualiza(void* x, int y){
  contador*aux = lista;
  while (aux!=NULL){
      if(aux->endereco == x){
          aux->referencias += y;
      if(aux->referencias==0)
        lista = liberamem(lista,lista->prox,lista);
      break;}
    aux = aux->prox;
  }
}

void* malloc2(size_t tam){

    void* x = malloc(tam);

    return x;
}

void atrib2(int *x, int *y){
    if(x!=NULL){
      atualiza(x,-1);
      if(y!=NULL)
          atualiza(y,1);
    }
    *x=*y;
}
