// Faça uma função que, dado um arquivo A
// contendo números reais, um por linha, crie um
// novo arquivo B contendo os mesmos
// elementos de A, porém ordenados
// decrescentemente e sem repetição.

#include <stdio.h>

int criarArquivo (char arqA, char arqB);

int main (void) {
    
    
    return 0;
}

int criarArquivo (char nomeArqA, char nomeArqB) {
    FILE *arqA, *arqB;
    float num;

    arqA = fopen(nomeArqA, "r");
        arqB = fopen(nomeArqB, "w");

    if ((!arqA) || (!arqB)) {
        return 0;
    } else {
        while (fscanf(arqA, "%f", &num) != EOF) {

        }
    }
}

