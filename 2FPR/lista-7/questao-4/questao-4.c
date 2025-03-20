// Considere a existência de um vetor de structs
// com quant posições, onde cada uma destas
// armazena os seguintes dados sobre um grupo
// de pessoas: nome (string), gênero (char) e
// idade (int). Pede-se uma função que determine
// se os elementos deste vetor estão ordenados e
// retorne 1, caso estejam ordenados, e 0, caso
// contrário.

// Observação: o vetor será considerado ordenado se
// estiver organizado crescentemente em função da
// idade. Porém, no caso de pessoas com a mesma
// idade, estas devem estar ordenadas crescentemente
// pelo nome.

#include <stdio.h>
#include <string.h>
#define QUANT 4

typedef struct {
    char nome[20];
    char genero;
    int idade;
} TPessoas;

void preencherVetor (TPessoas grupo[]) {
    strcpy(grupo[0].nome, "Arthur");
    grupo[0].genero = 'M';
    grupo[0].idade = 20;

    strcpy(grupo[1].nome, "Helena");
    grupo[1].genero = 'F';
    grupo[1].idade = 22;

    strcpy(grupo[2].nome, "Marcos");
    grupo[2].genero = 'M';
    grupo[2].idade = 22;

    strcpy(grupo[3].nome, "Emily");
    grupo[3].genero = 'F';
    grupo[3].idade = 23;
}

int checarOrdem (TPessoas grupo[], int quantidade) {
    int i;
    for (i = 1; i < quantidade; i++) {
        if (grupo[i].idade < grupo[i-1].idade) {
            return 0;
        } else if (grupo[i].idade == grupo[i-1].idade) {
            if (strcmp(grupo[i].nome, grupo[i-1].nome) < 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main () {
    TPessoas grupo[QUANT];
    int quantidade = QUANT;

    preencherVetor(grupo);

    if (checarOrdem(grupo, quantidade)) {
        printf ("Vetor Ordenado");
    } else {
        printf ("Vetor Desordenado");
    }

    return 0;
}