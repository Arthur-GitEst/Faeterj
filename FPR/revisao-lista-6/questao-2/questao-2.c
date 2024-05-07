// Dada uma string s, desenvolver uma função
// que determine se s é ou não um palíndromo.

// Observação: uma string s será um palíndromo
// quando seus caracteres formarem a mesma
// sequência, independente se s é percorrida da
// esquerda para direita ou vice-versa.

#include <stdio.h>
#include <string.h>

int determinarPalindromo (char s[]);

int main () {
    char s[] = "arttra";

    if (determinarPalindromo(s)) {
        printf("E palindromo");
    } else {
        printf ("Nao e palindromo");
    }
    
    return 0;
}

int determinarPalindromo (char s[]) {
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}