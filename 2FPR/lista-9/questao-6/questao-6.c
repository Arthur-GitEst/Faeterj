// Desenvolver uma função que, dados dois
// arquivos textos arqA e arqB, crie um novo
// arquivo arqC, considerando que:

// * arqA e arqB contém números reais,
// um por linha, ordenados
// crescentemente e sem repetição no
// arquivo;
// * arqC deve conter todos os números
// dos dois arquivos originais;
// * Assim como arqA e arqB, arqC
// também não possuirá repetições de
// elementos e estes deverão estar
// ordenados de forma crescente.

#include <stdio.h>
#include <float.h>

int unirArquivos (char nomeArqA[], char nomeArqB[], char nomeArqC[]);

int main () {
    unirArquivos("arquivoA.txt", "arquivoB.txt", "arquivoC.txt");
    
    return 0;
}

int unirArquivos (char nomeArqA[], char nomeArqB[], char nomeArqC[]) {
    FILE *arqA, *arqB, *arqC;
    int fimA = 0, fimB = 0;
    float numA, numB;

    arqA = fopen(nomeArqA, "r");
    arqB = fopen(nomeArqB, "r");
    arqC = fopen(nomeArqC, "w");

    if ((!arqA) || (!arqB) || (!arqC)) {
        fclose(arqA);
        fclose(arqB);
        fclose(arqC);
        return 0;
    } else {
        fscanf(arqA, "%f", &numA);
        fscanf(arqB, "%f", &numB); 

        while ((!fimA) && (!fimB)) {
            if (numA < numB) {
                fprintf(arqC, "%.1f\n", numA);
                if (fscanf(arqA, "%f", &numA) == EOF) {
                    fimA = 1;
                }
            } else if (numA > numB) {
                fprintf(arqC, "%.1f\n", numB);
                if (fscanf(arqB, "%f", &numB) == EOF) {
                    fimB = 1;
                }
            } else {
                fprintf(arqC, "%.1f\n", numA);
                if (fscanf(arqA, "%f", &numA) == EOF) {
                    fimA = 1;
                }
                if (fscanf(arqB, "%f", &numB) == EOF) {
                    fimB = 1;
                }
            }
        }
        if (!fimA) {
            fprintf(arqC, "%.1f\n", numA);
            while (fscanf(arqA, "%f", &numA) != EOF) {
                fprintf(arqC, "%.1f\n", numA);
            }
        }
        if (!fimB) {
            fprintf(arqC, "%.1f\n", numB);
            while (fscanf(arqB, "%f", &numB) != EOF) {
                fprintf(arqC, "%.1f\n", numB);
            }
        }
    }
    fclose(arqA);
    fclose(arqB);
    fclose(arqC);
    return 1;
}

