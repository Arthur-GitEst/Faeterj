// Dada uma string s, desenvolver uma função
// recursiva que determine se s é ou não um
// palíndromo.

#include <stdio.h>
#include <string.h>

int determinarPalindromo (char s[], int i, int j);

int main () {
    char s[] = "arara";
    int valorInicial = 0, valorFinal = strlen(s) - 1;

    if (determinarPalindromo(s, valorInicial, valorFinal)) {
        printf("E palindromo");
    } else {
        printf("Nao e palindromo");
    }
    
    return 0;
}

int determinarPalindromo (char s[], int i, int j) {
    if (i < j) {
        if (s[i] != s[j]) {
            return 0;
        } else {
            determinarPalindromo(s, i+1, j-1);
        }
    }
    return 1;    
}