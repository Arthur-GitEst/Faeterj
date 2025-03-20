// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de caracteres no
// mesmo.

#include <stdio.h>

int contarCaracteres (char nomeArq[]);

int main (void) {
    char arquivo[30];
    int resultado;

    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    gets(arquivo);

    resultado = contarCaracteres(arquivo);

    if (resultado == -1) {
        printf("\nArquivo nao pode ser aberto");
    } else {
        printf("\nO arquivo contém %d caracteres", resultado);
    }

    return 0;
}

int contarCaracteres (char nomeArq[]) {
    FILE* arq;
    int cont = 0;
    char ch;

    arq = fopen(nomeArq, "r");

    if (!arq) {
        return -1;
    } else {
        while (fscanf(arq, "%c", &ch) != EOF) {
            cont++;
        }
        fclose(arq);
        return cont;
    }
}