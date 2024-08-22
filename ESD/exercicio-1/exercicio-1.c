
#include "./functions.h"

int main () {
    int quantidade = 3;
    char *vNomesE[quantidade];
    char **vNomesD = (char**)malloc(quantidade * sizeof(char*));

    preencherDinamico(vNomesD, quantidade);

    exibir(vNomesD, quantidade);

    ordenar(vNomesD, quantidade);

    exibir(vNomesD, quantidade);

    return 0;
}

