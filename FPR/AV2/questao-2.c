#include <stdio.h>
#include <float.h>

int criarArquivo (char nomeArqA[], char nomeArqB[]);
int buscarValor (char nomeArq[], float *valor, float menor, int *ocorrencias);
int contarOcorrencias (char nomeArq[], float valor);

int main () {
    criarArquivo("ArquivoA.txt", "ArquivoB.txt");

    return 0;
}

int criarArquivo (char nomeArqA[], char nomeArqB[]) {
    FILE *arqB;
    float valor, menor = FLT_MIN;
    int ocorrencias;

    arqB = fopen(nomeArqB, "w");

    if (!arqB) {
        fclose(arqB);
        return 0;
    } else {
        fprintf(arqB, "Valor | Ocorrencias\n");
        while (buscarValor(nomeArqA, &valor, menor, &ocorrencias)) {
            ocorrencias =  contarOcorrencias(nomeArqA, valor);
            fprintf(arqB, "%.1f | %d\n", valor, ocorrencias);
            menor = valor;
        }
        fclose(arqB);
        return 1;
    }
}

int buscarValor (char nomeArq[], float *valor, float menor, int *ocorrencias) {
    FILE *arq;
    float num;
    int aux = 0;

    *ocorrencias = 0;
    *valor = FLT_MAX;

    arq = fopen(nomeArq, "r");

    if (!arq) {
        fclose(arq);
        return -1;
    } else {
        while (fscanf(arq, "%f", &num) != EOF) {
            if ((num < *valor) && (num > menor)) {
                *valor = num;
                aux = 1;
            }
        }
        fclose(arq);
        return aux; 
    }

}

int contarOcorrencias (char nomeArq[], float valor) {
    FILE *arq;
    float num;
    int cont = 0;

    arq = fopen(nomeArq, "r");

    if (!arq) {
        fclose(arq);
        return -1;
    } else {
        while (fscanf(arq, "%f", &num) != EOF) {
            if (num == valor) {
                cont++;
            }
        }
        fclose(arq);
        return cont;
    }
}