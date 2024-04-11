// Uma loja de automóveis mantém os carros à
// venda sob a forma de um vetor de structs
// contendo as seguintes informações, para cada
// veículo: placa, modelo, marca, cor,
// quilometragem, ano modelo/fabricação (deve
// ser um struct), valor e tipo (usado ou 0 km,
// conforme o valor do campo quilometragem).
// Pede-se a declaração de uma variável que
// represente o estoque de veículos da loja,
// incluindo todas as declarações de tipos que
// possam ser necessárias.
// Além disso, implementar as seguintes funções:

// i. Exibir todos os carros do modelo m, ano de
// fabricação entre a1 e a2 (inclusive), com
// valor não superior a x reais;

// ii. Reajustar os valores de todos os carros 0
// km, considerando um aumento de p %;

// iii. Retirar do estoque um determinado veículo,
// dada a sua placa.

#include <stdio.h>
#include <string.h>
#define QUANT 3

typedef struct TVeiculos {
    char placa[8];
    char modelo[20];
    char marca[20];
    char cor[15];
    float quilometragem;
    int ano;
    float valor;
    int usadoOuZero;
} TVeiculos;

void preencherCarros1 (TVeiculos *veiculo) {
    int i;
    for (i = 0; i < QUANT; i++) {
        printf("Modelo: ");
        fflush(stdin);
        gets(veiculo[i].modelo);

        printf("Ano: ");
        scanf("%d", &veiculo[i].ano);

        printf("Valor: ");
        scanf("%f", &veiculo[i].valor);
    }
}

void exibirCarros(TVeiculos veiculo) {
    int i;
    for (i = 0; i < QUANT; i++) {
        if ()
    }
}

int main () {
    TVeiculos veiculo[QUANT];
    int a1 = 2015, a2 = 2020;
    float x = 13000;

    return 0;
}
