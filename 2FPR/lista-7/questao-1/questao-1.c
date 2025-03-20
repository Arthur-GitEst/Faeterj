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
    char placa[10];
    char modelo[20];
    char marca[20];
    char cor[20];
    float quilometragem;
    int ano;
    float valor;
    char tipo[10];
} TVeiculos;


void preencherVetor (TVeiculos loja[]) {
    strcpy(loja[0].placa, "123 ABCD");
    strcpy(loja[0].modelo, "Logan");
    strcpy(loja[0].marca, "Renault");
    strcpy(loja[0].cor, "Prata");
    loja[0].quilometragem = 0;
    loja[0].ano = 2018;
    loja[0].valor = 28000;
    strcpy(loja[0].tipo, "0km");

    strcpy(loja[1].placa, "234 BCDE");
    strcpy(loja[1].modelo, "Cruze");
    strcpy(loja[1].marca, "Chevrolet");
    strcpy(loja[1].cor, "Cinza");
    loja[1].quilometragem = 20000;
    loja[1].ano = 2020;
    loja[1].valor = 26000;
    strcpy(loja[1].tipo, "Usado");

    strcpy(loja[2].placa, "345 CDEF");
    strcpy(loja[2].modelo, "Cruze");
    strcpy(loja[2].marca, "Chevrolet");
    strcpy(loja[2].cor, "Branco");
    loja[2].quilometragem = 0;
    loja[2].ano = 2019;
    loja[2].valor = 24600;
    strcpy(loja[2].tipo, "0km");
}

void exibirVeiculos (TVeiculos veiculo) {
        printf("%s\n", veiculo.placa);
        printf("%s\n", veiculo.modelo);
        printf("%s\n", veiculo.marca);
        printf("%s\n", veiculo.cor);
        printf("%f\n", veiculo.quilometragem);
        printf("%d\n", veiculo.ano);
        printf("%.2f\n", veiculo.valor);
        printf("%s\n", veiculo.tipo);
        printf("\n");
}

void exibirVeiculosGeral (TVeiculos loja[], int quantidade) {
        int i;
        for (i = 0; i < quantidade; i++) {
            printf("%s\n", loja[i].placa);
            printf("%s\n", loja[i].modelo);
            printf("%s\n", loja[i].marca);
            printf("%s\n", loja[i].cor);
            printf("%f\n", loja[i].quilometragem);
            printf("%d\n", loja[i].ano);
            printf("%.2f\n", loja[i].valor);
            printf("%s\n", loja[i].tipo);
            printf("\n");
        }
}

int filtrarVeiculos (TVeiculos loja[], int quantidade, char modelo[], int anoInicial, int anoFinal, float valorMaximo) {
    int i, cont = 0;
    for (i = 0; i < quantidade; i++) {
        if ((strcmp(modelo, loja[i].modelo) == 0) && (loja[i].ano <= anoFinal) && (loja[i].ano >= anoInicial) && (loja[i].valor <= valorMaximo)) {
            exibirVeiculos(loja[i]);
            cont++;
        }
    }
    return cont;
}

int reajustarValor (TVeiculos loja[], int quantidade, float porcentagem) {
    float p = porcentagem / 100;
    int i, cont = 0;
    for (i = 0; i < quantidade; i++) {
        if (strcmp("0km", loja[i].tipo) == 0) {
            loja[i].valor *= (1 + p);
            cont++;
        }
    }
    return cont;
}

int removerVeiculo (TVeiculos loja[], int *quantidade, char placa[]) {
    int i;
    for (i = 0; i < *quantidade; i++) {
        if (strcmp(placa, loja[i].placa) == 0) {
            loja[i] = loja[(*quantidade) - 1];
            (*quantidade)--;
            return 1;
        }
    }
    return 0;
}

int main() {
    TVeiculos loja[QUANT];
    int quantidade = QUANT;

    preencherVetor(loja);

    // if (filtrarVeiculos(loja, quantidade, "Cruze", 2019, 2021, 26500) == 0) {
    //     printf("Veiculo nao encontrado\n");
    // }

    // if (reajustarValor(loja, quantidade, 10) == 0) {
    //     printf("Nenhum veiculo segue esse parametro\n");
    // }
    // exibirVeiculosGeral(loja, quantidade);

    if (removerVeiculo(loja, &quantidade, "123 ABCD") == 0) {
        printf("Nenhum veiculo com essa placa\n");
    }
    exibirVeiculosGeral(loja, quantidade);
    
    return 0;
}
