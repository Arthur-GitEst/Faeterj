#include <stdio.h>

int funcao (int A, int B) {
    if (A >= B) {
        return funcao (A-B, B);
    } else {
        return A;
    }
}

int main () {
    int x = funcao(32,6);
    printf("%d\n", x);
    // deve retornar 2
}