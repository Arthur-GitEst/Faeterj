#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./tarefa-2.h"

int main () {
    char *vNomAux[20] = {"Ana", "Bruno", "Carolina", "Daniel", "Eduardo", "Fernanda", "Gustavo", "Henrique", "Isabela", "Joao", "Karina", "Lucas", "Mariana", "Nathan", "Olivia", "Pedro", "Queila", "Rafael", "Sofia", "Tiago"};
    char pessoaEscolhida[20];
    int quant, limiar, resultado;

    srand(time(NULL));
    printf("\nInsira o numero de pessoas: ");
    scanf("%d", &quant);
    tPessoa vPessoas[quant];
    inicializarPessoas(vPessoas, vNomAux, quant);
    printf("\nDigite o nome da pessoa escolhida: ");
    scanf("%s", pessoaEscolhida);
    printf("\nInsira o limiar (de 1 a 19): ");
    scanf("%d", &limiar);

    resultado = encontrarCompatibilidade(pessoaEscolhida, vPessoas, limiar, quant);

    if (resultado == -1) {
        printf("Pessoa Invalida");
    } else if (resultado == 0) {
        printf("Ninguem e compativel com %s", pessoaEscolhida);
    } else {
        printf("\nNo total, %d pessoas sao compativeis com %s\n", resultado, pessoaEscolhida);
    }

    return 0;
}