// Suponha a exist�ncia de um vetor de tamanho
// TAM, cada posi��o armazenando o nome da
// pessoa e a sua data de anivers�rio
// (representada por um struct do tipo TData,
// contendo os campos dia e mes). Pede-se o
// desenvolvimento das seguintes fun��es:

// ? Determinar a quantidade de pessoas que
// fazem anivers�rio no m�s M;

// ? Exibir os nomes de todas pessoas que fazem
// anivers�rio entre as datas d1 e d2, ambas
// do tipo TData.

#include <stdio.h>
#include <string.h>
#define TAM 4

typedef struct {
    int dia;
    int mes;
} TData;

typedef struct {
    char nome [20];
    TData aniversario;
} TPessoa;

void preencherVetor (TPessoa grupo[]) {
    strcpy(grupo[0].nome, "Arthur");
    grupo[0].aniversario.dia = 20;
    grupo[0].aniversario.mes = 7;

    strcpy(grupo[1].nome, "Helena");
    grupo[1].aniversario.dia = 29;
    grupo[1].aniversario.mes = 10;

    strcpy(grupo[2].nome, "Marcos");
    grupo[2].aniversario.dia = 6;
    grupo[2].aniversario.mes = 4;

    strcpy(grupo[3].nome, "Emily");
    grupo[3].aniversario.dia = 15;
    grupo[3].aniversario.mes = 7;
}

void exibirPessoas (TPessoa pessoa) {
    printf("Nome: %s\n", pessoa.nome);
    printf("Data de Aniversario: %d/%d\n", pessoa.aniversario.dia, pessoa.aniversario.mes);
    printf("\n");
}

int contarPessoas (TPessoa grupo[], int quantidade, int mes) {
    int i, cont = 0;
    for (i = 0; i < quantidade; i++) {
        if (grupo[i].aniversario.mes == mes) {
            cont++;
        }
    }
    return cont;
}

int exibirAniversariantes (TPessoa grupo[], int quantidade, TData d1, TData d2) {
    int i, cont = 0;
    for (i = 0; i < quantidade; i++) {
        if ((grupo[i].aniversario.mes >= d1.mes) && (grupo[i].aniversario.mes <= d2.mes)) {
            if((grupo[i].aniversario.dia >= d1.dia) && (grupo[i].aniversario.dia <= d2.dia)) {
                exibirPessoas(grupo[i]);
                cont++;
            }
        }
    }
}

int main() {
    TPessoa grupo[TAM];
    TData data1 = {2, 4}, data2 = {17,7};
    int quantidade = TAM, mes = 7;

    preencherVetor(grupo);

    // int quantAniversariantes = contarPessoas(grupo, quantidade, mes);
    // if (quantAniversariantes == 0) {
    //     printf("Ninguem faz aniversario no mes %d\n", mes);
    // } else {
    //     printf("No mes %d, ha %d aniversariante(s)\n", mes, quantAniversariantes);
    // }

    if (exibirAniversariantes(grupo, quantidade, data1, data2) == 0) {
        printf("Ninguem faz aniversario nessas datas");
    }
    
    return 0;
}