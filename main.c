#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

int main() {
    ArvoreRB raiz = NULL; // Inicializa a árvore


    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    int numValores = sizeof(valores) / sizeof(valores[0]);
	int i;
    for (i = 0; i < numValores; i++) {
        int resp;
        insere_ArvoreRB(&raiz, valores[i]);
        printf("Inserindo o valor %d na árvore\n", valores[i]);
    }

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

