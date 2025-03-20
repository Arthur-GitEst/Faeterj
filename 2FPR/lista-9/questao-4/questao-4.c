//Desenvolver uma função que, dado um arquivo
// texto contendo números, determine se estes
// encontram-se ordenados crescentemente.

#include <stdio.h>
#include <limits.h>

int determinarOrdem (char nomeArq[]);

int main (void) {
    char arquivo[30];

    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets(arquivo);

    switch (determinarOrdem(arquivo)) {
        case -1:
        printf("\nArquivo nao pode ser aberto.");
        break;

        case 0:
        printf("\nArquivo nao e ordenado em ordem crescente.");
        break;

        case 1:
        printf("\nArquivo e ordenado em ordem crescente.");
        break;
    }
    
    return 0;
}

int determinarOrdem (char nomeArq[]) {
    FILE* arq;
    int num, anterior = INT_MIN;

    arq = fopen(nomeArq, "r");
    
    if (!arq) {
        return -1;
    } else {
        while (fscanf(arq, "%d", &num) != EOF) {
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