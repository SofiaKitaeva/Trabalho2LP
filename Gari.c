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
    novo->prox=NULL;
    if(lista==NULL)
        lista=novo;
    else{
        contador* aux = lista;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=novo;
    }
    
	return novo->endereco;
}

contador *liberamem(contador* l, contador* aux, contador* prim){
  if(prim->referencias == 0){
    	free(l);
		return aux;
  }
	else if(aux->referencias == 0){
		l->prox = aux->prox;
    	free(aux);
		return l;
	}
	else
		return liberamem(l->prox,aux->prox,prim);
}

void atualiza(void* x, int y){
  contador*aux = lista;
  while (aux!=NULL){
    	if(aux->endereco == x){
        	aux->referencias += y;
      		if(aux->referencias==0)
        		lista = liberamem(lista,lista->prox,lista);
      		break;
		}
    	aux = aux->prox;
	}
}

void* malloc2(size_t tam){
	
    void* x = InsereCont(tam);
	
    return x;
}

void atrib2(int *x, int *y){
	if(x!=NULL){
      atualiza(x,-1);
      if(y!=NULL)
          atualiza(y,1);
    }
    
    if(y==NULL)
    	x=NULL;
    else
    	*x=*y;
}

void dump(){
  printf("\n\n Situação da memória\n");
  contador* aux=lista;
  while(aux!=NULL) {
      printf("Local na memória: %p  Contador: %d\n",aux->endereco, aux->referencias);
      aux=aux->prox;
  }
}
