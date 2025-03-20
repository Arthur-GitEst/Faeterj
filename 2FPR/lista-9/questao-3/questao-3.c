// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de letras existentes
// no mesmo (entendendo que no arquivo podem
// existir letras, algarismos e símbolos).

#include <stdio.h>

int verificarLetras (char nomeArq[]);

int main (void) {
    char arquivo[30];
    int resultado;

    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    gets(arquivo);

    resultado = verificarLetras(arquivo);

    if (resultado == -1) {
        printf("\nArquivo nao pode ser aberto!");
    } else {
        printf("O arquivo contem %d letras.", resultado);
    }
    
    return 0;
}

int verificarLetras (char nomeArq[]) {
    FILE* arq;
    char ch;
    int cont = 0;

    arq = fopen(nomeArq, "r");

    if (!arq) {
        return -1;
    } else {
        while (fscanf(arq, "%c", &ch) != EOF) {
            ch = toupper(ch);
            if ((ch >= 'A') && (ch <= 'Z')) {
                cont++;
            }
        }
        fclose(arq);
        return cont;
    }
}