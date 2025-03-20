// Pede-se a implementação de uma função
// recursiva que exiba os n primeiros termos de
// uma PG (Progressão Geométrica), onde a1 é o
// seu primeiro termo e q a razão.

#include <stdio.h>

void progressaoPG (int a1, int q, int n);

int main () {
    int a1 = 1, q = 3, n = 10;

    progressaoPG(a1, q, n);
    
    return 0;
}

void progressaoPG (int a1, int q, int n) {
    if (n > 0) {
        printf("%d ", a1);
        progressaoPG(a1*q, q, n-1);
    }
}