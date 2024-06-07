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
#define TAM 4

typedef struct {
    int fabricacao;
    int modelo;
} TAno;

typedef struct {
    char placa[10];
    char modelo[20];
    char marca[20];
    char cor[20];
    float quilometragem;
    TAno ano;
    float valor;
    char tipo[10];
} TVeiculos;

void preencherVetor (TVeiculos veiculos[]);
void exibirCarros (TVeiculos veiculos[], int quantidade, char modelo[], int a1, int a2, float valorMax);
void printarCarro(TVeiculos veiculos);

int main (void) {
    TVeiculos veiculos[TAM];
    int quantidade = TAM;

    preencherVetor(veiculos);

    exibirCarros(veiculos, quantidade, "Cruze", 2019, 2021, 46000);
    
    return 0;
}

void printarCarro(TVeiculos veiculos) {
    printf("%s\n", veiculos.placa);
    printf("%s\n", veiculos.modelo);
    printf("%s\n", veiculos.marca);
    printf("%s\n", veiculos.cor);
    printf("%f\n", veiculos.quilometragem);
    printf("%d\n", veiculos.ano.fabricacao);
    printf("%d\n", veiculos.ano.modelo);
    printf("%f\n", veiculos.valor);
    printf("%s\n", veiculos.tipo);
    printf("\n");
}

void exibirCarros (TVeiculos veiculos[], int quantidade, char modelo[], int a1, int a2, float valorMax) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if ((strcmp(veiculos[i].modelo, modelo) == 0) && (veiculos[i].ano.fabricacao >= a1) && (veiculos[i].ano.fabricacao <= a2) && (veiculos[i].valor <= valorMax)) {
            printarCarro(veiculos[i]);
        }
    }
}


void preencherVetor (TVeiculos veiculos[]) {
    strcpy(veiculos[0].placa, "123 ABCD");
    strcpy(veiculos[0].modelo, "Logan");
    strcpy(veiculos[0].marca, "Renault");
    strcpy(veiculos[0].cor, "Prata");
    veiculos[0].quilometragem = 75000;
    veiculos[0].ano.fabricacao = 2013;
    veiculos[0].ano.modelo = 2012;
    veiculos[0].valor = 21000;
    strcpy(veiculos[0].tipo, "Usado");
    
    strcpy(veiculos[1].placa, "234 BCDE");
    strcpy(veiculos[1].modelo, "Cruze");
    strcpy(veiculos[1].marca, "Chevrolet");
    strcpy(veiculos[1].cor, "Cinza Escuro");
    veiculos[1].quilometragem = 0;
    veiculos[1].ano.fabricacao = 2020;
    veiculos[1].ano.modelo = 2018;
    veiculos[1].valor = 34500;
    strcpy(veiculos[1].tipo, "0KM");
    
    strcpy(veiculos[2].placa, "345 CDEF");
    strcpy(veiculos[2].modelo, "UNO");
    strcpy(veiculos[2].marca, "Fiat");
    strcpy(veiculos[2].cor, "Vermelho");
    veiculos[2].quilometragem = 0;
    veiculos[2].ano.fabricacao = 2016;
    veiculos[2].ano.modelo = 2015;
    veiculos[2].valor = 27500;
    strcpy(veiculos[2].tipo, "0KM");

    strcpy(veiculos[3].placa, "456 DEFG");
    strcpy(veiculos[3].modelo, "Emprenza");
    strcpy(veiculos[3].marca, "Subaru");
    strcpy(veiculos[3].cor, "Azul");
    veiculos[3].quilometragem = 27000;
    veiculos[3].ano.fabricacao = 2022;
    veiculos[3].ano.modelo = 2022;
    veiculos[3].valor = 37400;
    strcpy(veiculos[3].tipo, "Usado");
}