// Considere a existência de um vetor de structs
// com quant posições, onde cada uma destas
// armazena os seguintes dados sobre os
// funcionários de uma empresa: matricula (int),
// nome (string), gênero (char) e salário (float).
// Pede-se uma função que, dado um gênero,
// desloque todos os funcionários deste gênero
// para o início do vetor (e, consequentemente, os
// funcionários do outro gênero ficarão ao final do
// conjunto).

#include <stdio.h>
#include <string.h>
#define QUANT 4

typedef struct {
    int matricula;
    char nome[50];
    char genero; 
    float salario;
} TFuncionaros;

void preencherVetor (TFuncionaros empresa[]) {
    empresa[0].matricula = 1;
    strcpy(empresa[0].nome, "Arthur");
    empresa[0].genero = 'M';
    empresa[0].salario = 4500;

    empresa[1].matricula = 2;
    strcpy(empresa[1].nome, "Helena");
    empresa[1].genero = 'F';
    empresa[1].salario = 5500;

    empresa[2].matricula = 3;
    strcpy(empresa[2].nome, "Marcos");
    empresa[2].genero = 'M';
    empresa[2].salario = 4700;

    empresa[3].matricula = 4;
    strcpy(empresa[3].nome, "Emily");
    empresa[3].genero = 'F';
    empresa[3].salario = 6600;
}

void exibirFuncionarios (TFuncionaros empresa[], int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        printf("Matricula: %d\n", empresa[i].matricula);
        printf("Nome: %s\n", empresa[i].nome);
        if (empresa[i].genero == 'F') {
            printf("Genero: Feminino\n");
        } else {
            printf("Genero: Masculino\n");
        }
        // printf("Genero: %s\n", (empresa[i].genero=='F'?"Feminino":"Masculino"));
        printf("Salario: %.2f\n", empresa[i].salario);
        printf("\n");
    }
}

void organizarFuncionarios (TFuncionaros empresa[], int quantidade, char genero) {
    int i = 0, j = (quantidade - 1);
    TFuncionaros aux;
    while (i < j) {
        if (empresa[i].genero == genero) {
            i++;
        } else {
            if (empresa[j].genero != genero) {
                j--;
            } else {
                aux = empresa[i];
                empresa[i] = empresa[j];
                empresa[j] = aux;
                i++;
                j--;
            }
        }
    }
}

int main() {
    TFuncionaros empresa[QUANT];
    int quantidade = QUANT;

    preencherVetor(empresa);
    organizarFuncionarios(empresa, quantidade, 'F');
    exibirFuncionarios(empresa, quantidade);
    
    return 0;
}

