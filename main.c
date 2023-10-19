#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

int main() {
    ArvoreRB raiz = NULL; // Inicializa a �rvore


    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    int numValores = sizeof(valores) / sizeof(valores[0]);
	int i;
    for (i = 0; i < numValores; i++) {
        int resp;
        insere_ArvoreRB(&raiz, valores[i]);
        printf("Inserindo o valor %d na �rvore\n", valores[i]);
    }

    // Realizar uma busca na �rvore
    int busca = 15;
    struct NO* resultado = busca_ArvoreRB(raiz, busca);

    if (resultado != NULL) {
        printf("Valor %d encontrado\n", busca);
    } else {
        printf("Valor %d n�o encontrado\n", busca);
    }

    return 0;
}

