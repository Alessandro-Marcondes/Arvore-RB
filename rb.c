#include <stdio.h>
#include <stdlib.h>
#include "rb.h"


#define RED 1
#define BLACK 0

int cor (struct NO* h){
	if(h == NULL){
		return BLACK; 
	}else{
		return h->cor;
	}
}

//Inverte a cor do pai e dos filhos
void trocaCor(struct NO* h){
	h->cor = !h->cor;
	if(h->esq != NULL){
		h->esq->cor = !h->esq->cor;
	}
	if(h->dir != NULL){
		h->dir->cor = !h->dir->cor;
	}
}


struct NO* rotEsquerda(struct NO* A){
	struct NO* B = A->dir;
	A->dir = B->esq;
	B->esq = A;
	B->cor = A->cor;
	A->cor = RED;
	return B;
}

struct NO* rotDireita(struct NO* A){
	struct NO* B = A->esq;
	A->esq = B->dir;
	B->dir = A;
	B->cor = A->cor;
	A->cor = RED;
	return B;
}

/*
struct NO* move2EsqRED(struct NO* h){
	trocaCor(h);
	if(cor(h->dir->esq) == RED){
		h->dir = rotDireita(h->dir);
		h = rotEsquerda(h);
		trocaCor(h);
	}
	return h;
}


struct NO* move2DirRED(struct NO* h){
	trocaCor(h);
	if(cor(h->esq->dir) == RED){
		h = rotDireita(h);
		trocaCor(h);
	}
	return h;
}

*/

struct NO* balancear(struct NO* h){
	if(cor(h->dir) == RED){
	 h = rotEsquerda(h); //nó vermelho é sempre filho esquerdo
	}
	if(h->esq !=NULL && cor(h->dir) == RED && cor(h->esq->esq) == RED){
		h = rotDireita(h); //Filho direito e neto esquerdo são vermelhos
	}
	if(cor(h->esq) == RED && cor(h->dir) == RED){
		trocaCor(h); //2 filhos vermelhos troca a cor
	}
	return h;
}
	
int insere_ArvoreRB(ArvoreRB* raiz, int valor){
	int resp;
	*raiz = insereNO(*raiz, valor,&resp);
	if((*raiz) != NULL){
		(*raiz)->cor = BLACK;
	}
	return resp;
}

struct NO* insereNO(struct NO* h, int valor, int *resp){
	if(h == NULL){
		struct NO *novo;
		novo = (struct NO*) malloc(sizeof(struct NO));
		if(novo == NULL){
			*resp = 0;
			return NULL;
		}
		novo->info = valor;
		novo->cor = RED;
		novo->dir = NULL;
		novo->esq = NULL;
		*resp = 1;
		return novo;
	}
	
	if(valor <h->info){
		h->esq = insereNO(h->esq,valor,resp);
	}else{
		h->dir = insereNO(h->dir,valor,resp);
	}
	
	if(cor(h->dir) == RED && cor(h->esq) == BLACK){
		h = rotEsquerda(h);
 	}
	if(cor(h->esq) == RED && cor(h->esq->esq) == RED){
		h = rotDireita(h);
	}
	if(cor(h->esq) == RED && cor(h->dir) == RED){
		trocaCor(h);
	}
	
	return h;
}


struct NO* busca_ArvoreRB(struct NO* h, int valor) {
    if (h == NULL) {
        return NULL;
    }
    
    if (valor == h->info) {
        return h;
    }
    
    if (valor < h->info) {
        return busca_ArvoreRB(h->esq, valor);
    } else {
        return busca_ArvoreRB(h->dir, valor);
    }
}

