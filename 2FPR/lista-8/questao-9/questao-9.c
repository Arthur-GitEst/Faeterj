// Desenvolver uma função recursiva que, dado
// um vetor V com quant números inteiros,
// determine se seus elementos estão dispostos
// de maneira a representar uma progressão
// aritmética.

#include <stdio.h>
#define QUANT 5

int verificarVetor (int v[], int quantidade, int i);

int main () {
    int v[QUANT] = {1, 3, 5, 7, 9}, quantidade = QUANT;

    if (verificarVetor(v, quantidade, 0)) {
        printf("E PA");
    } else {
        printf("Nao e PA");
    }
    
    return 0;
}

int verificarVetor (int v[], int quantidade, int i) {
    if (i < quantidade - 2) {
        int razao = v[1] - v[0];
        if (razao != (v[i+1] - v[i])) {
            return 0;
        } else {
            return verificarVetor(v, quantidade, ++i);
        }
    } else {
        return 1;
    }
}