//Desenvolver uma função que, dado um arquivo
// texto contendo números, determine se estes
// encontram-se ordenados crescentemente.

#include <stdio.h>
#include <limits.h>

int determinarOrdem (char nomeArq[]);

int main (void) {
    char nomeArq;

    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets

    switch (determinarOrdem(nomeArq)) {
        case -1:
        printf("Arquivo nao pode ser aberto.");
        break;

        case 0:
        printf("Arquivo nao e ordenado em ordem crescente.");
        break;

        case 1:
        printf("Arquivo e ordenado em ordem crescente.");
        break;
    }
    
    return 0;
}

int determinarOrdem (char nomeArq[]) {
    FILE* arq;
    int num, anterior = INT_MIN;

    fopen(nomeArq, "r");
    
    if (!arq) {
        return -1;
    } else {
        while (fscanf(arq, "%c", num) != EOF) {
            if (num < anterior) {
                fclose(arq);
                return 0;
            }
            anterior = num;
        }
        fclose(arq);
        return 1;
    }
}