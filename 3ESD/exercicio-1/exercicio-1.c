#include "./functions.h"

int main () {
    int quantidade = 3, opcao;
    char *vNomesE[quantidade];
    char **vNomesD = (char**)malloc(quantidade * sizeof(char*));

    do {
        printf("Selecione uma opção:\n");
        printf("1 - Preencher Estaticamente\n");
        printf("2 - Preencher Dinamicamente\n");
        printf("3 - Ordenar Vetor\n");
        printf("4 - Exibir Vetor\n");
        printf("5 - Sair\n");

        printf("Opção: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                preencherEstatico(vNomesE, quantidade);
            case 2: 
                preencherDinamico(vNomesD, quantidade);
            case 3:
                ordenar(vNomesD, quantidade);
            case 4:
                exibir(vNomesD, quantidade);
            default:
                break;
        }
    } while (1);
    
    return 0;
}

