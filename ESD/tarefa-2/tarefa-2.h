#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

struct P {
    char *nome;
    int respQuestionario[N];
};

typedef struct P tPessoa;

void inicializarPessoas (tPessoa *pessoas, char **vNomes, int quant) {
    int i, j, resp, aux;

    printf("\nPessoas Incluidas:\n");
    for (i = 0; i < quant; i++) {
        //definindo nomes aleatórios
        aux = rand() % 20;
        pessoas[i].nome = (char*)malloc(strlen(vNomes[aux]) + 1);
        strcpy(pessoas[i].nome, vNomes[aux]);
        printf("%d - %s\n", i, pessoas[i].nome);    

        //definindo respostas aleatórias para cada pessoa N(10) vezes
        for (j = 0; j < N; j++) {
            pessoas[i].respQuestionario[j] = rand() % 10;
        }
    }
}

float calcularDistancia (tPessoa p1, tPessoa p2) {
    int i;
    float resultado = 0;

    //aplicando a fórmula para as duas pessoas
    for (i = 0; i < N; i++) {
        resultado += (p1.respQuestionario[i] - p2.respQuestionario[i]) * (p1.respQuestionario[i] - p2.respQuestionario[i]);
    }

    //retornando o resultado
    return sqrt(resultado);
}

int encontrarCompatibilidade (char *pessoaEscolhida, tPessoa *pessoas, int limiar, int quant) {
    tPessoa comparada;
    int i, indexComparada;

    //achando a pessoa escolhida e armazenando seu nome e respostas
    for (i = 0; (i < quant) && (strcmp(pessoaEscolhida, pessoas[i].nome) != 0); i++);

    if (i == quant) {
        return -1;
    }

    comparada = pessoas[i];
    indexComparada = i;

    //iniciando o resultado
    printf("\nPessoas compativeis com %s:\n", comparada.nome);

    //fazendo a comparação
    int soma = 0;
    for (i = 0; i < quant; i++) {
        if (i != indexComparada) {
            if (calcularDistancia(comparada, pessoas[i]) < limiar) {
                printf("%s\n", pessoas[i].nome);
                soma++;
            }
        }
    }

    //retronando o resultado
    return soma;
}