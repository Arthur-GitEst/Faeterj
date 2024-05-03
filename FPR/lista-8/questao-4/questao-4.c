// Fazer uma função recursiva que, dado um
// número inteiro N, exiba o mesmo na base 2
// (binária).

#include <stdio.h>

void converterBinario (int n);

int main () {
    int n = 64;

    converterBinario(n);
    
    return 0;
}

void converterBinario (int n) {
    if (n / 2 >= 1) {
        converterBinario(n / 2);
        printf("%d ", (n % 2));
    } else {
        printf("%d ", (n % 2));
    }
}