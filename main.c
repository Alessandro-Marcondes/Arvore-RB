#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

int main() {
    ArvoreRB raiz = NULL; // Inicializa a árvore

	insere_ArvoreRB(&raiz, 10);
	insere_ArvoreRB(&raiz, 5);
	insere_ArvoreRB(&raiz, 15);
	insere_ArvoreRB(&raiz, 3);
	insere_ArvoreRB(&raiz, 7);
	insere_ArvoreRB(&raiz, 12);
	insere_ArvoreRB(&raiz, 18);

    // Realizar uma busca na árvore
    int busca = 15;
    struct NO* resultado = busca_ArvoreRB(raiz, busca);

    if (resultado != NULL) {
        printf("Valor %d encontrado\n", busca);
    } else {
        printf("Valor %d não encontrado\n", busca);
    }

    return 0;
}

