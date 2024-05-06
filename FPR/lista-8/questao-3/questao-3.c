#include <stdio.h>

void exibirMultiplos (int n, int v, int aux);

int main () {
    int valor = 45, numero = 3, aux = numero;

    exibirMultiplos(numero, valor, aux);
}

void exibirMultiplos (int n, int v, int aux) {
    if (n <= v) {
        printf("%d\n", n);
        exibirMultiplos((n+aux), v, aux);
    }
}

// void exibirMultiplos (int n, int v, int aux) {
//     int i;
//     for (i = n; i <= v; i+=aux) {
//         printf("%d\n", i);
//     }
// }