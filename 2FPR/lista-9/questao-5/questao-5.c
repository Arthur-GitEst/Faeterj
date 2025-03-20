// Faça uma função que, dado um arquivo A
// contendo números reais, um por linha, crie um
// novo arquivo B contendo os mesmos
// elementos de A, porém ordenados
// decrescentemente e sem repetição.

#include <stdio.h>
#include <float.h>

int criarArquivo (char nomeArqA[], char nomeArqB[]);
int buscarMaior (char nomeArqA[], float *valor, float limite);

int main (void) {
    criarArquivo("questao-5.txt", "novo-5.txt");
    
    return 0;
}

int criarArquivo (char nomeArqA[], char nomeArqB[]) {
    FILE *arqB;
    float limite = FLT_MAX, valor;

    arqB = fopen(nomeArqB, "w");

    if (!arqB) {
        return 0;
    } else {
        while (buscarMaior(nomeArqA, &valor, limite)) {
            fprintf(arqB, "%.2f\n", valor);
            limite = valor;
        }
        fclose(arqB);
        return 1;
    }
}

int buscarMaior (char nomeArqA[], float *valor, float limite) {
    FILE *arqA;
    int achou = 0;
    float num;
    
    *valor = FLT_MIN;

    arqA = fopen(nomeArqA, "r");

    if (!arqA) {
        return -1;
    } else {
        while (fscanf(arqA, "%f", &num) != EOF) {
            if ((num > *valor) && (num < limite)) {
                *valor = num;
                achou = 1;
            }
        }
        fclose(arqA);
        return achou;
    }
}

