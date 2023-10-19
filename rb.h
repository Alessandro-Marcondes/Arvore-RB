#ifndef BST_H
#define BST_H

typedef struct NO* ArvoreRB;
 
 
struct NO{
	int info;
	struct NO *esq;
	struct NO *dir;
	int cor;
};


int cor (struct NO* h);
int insere_ArvoreRB(ArvoreRB* raiz, int valor);
void trocaCor(struct NO* h);
struct NO* rotEsquerda(struct NO* A);
struct NO* rotDireita(struct NO* A);
struct NO* balancear(struct NO* h);
int insere_ArvoreRB(ArvoreRB* raiz, int valor);
struct NO* insereNO(struct NO* h, int valor, int *resp);
struct NO* busca_ArvoreRB(struct NO* h, int valor);

#endif 


