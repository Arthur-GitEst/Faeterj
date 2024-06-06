// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de vezes que um
// determinado caracter aparece no arquivo.

#include <stdio.h>

// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de caracteres no
// mesmo.

#include <stdio.h>

int contarCaracter (char nomeArq[], char caracter);

int main (void) {
    char arquivo[30], caracter;
    int resultado;

    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    gets(arquivo);

    printf("Digite o caracter a ser contado: ");
    fflush(stdin);
    scanf("%c", &caracter);

    resultado = contarCaracter(arquivo, caracter);

    if (resultado == -1) {
        printf("\nArquivo nao pode ser aberto");
    } else {
        printf("\nO caracter aparece %d vezes", resultado);
    }

    return 0;
}

int contarCaracter (char nomeArq[], char caracter) {
    FILE* arq;
    int cont = 0;
    char ch;

    arq = fopen(nomeArq, "r");

    if (!arq) {
        return -1;
    } else {
        while (fscanf(arq, "%c", &ch) != EOF) {
            if (ch == caracter) {
                cont++;
            }
        }
        fclose(arq);
        return cont;
    }
}