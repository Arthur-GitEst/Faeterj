// Desenvolver uma função que, dada uma string
// s, crie uma substring que inicie na posição p de
// s e contenha n caracteres.

// Observações: se p e/ou n forem inválidos, a
// substring será vazia; ii) se s não possuir n
// caracteres além de p, a substring a ser criada
// começará em p e terminará no final de s.

#include <stdio.h>
#include <string.h>

void criarSubstring (char s[], char sub[], int p, int n);

int main () {
    char s[] = "algoritmo", sub[] = "";
    int p = 4, n = 5;

    criarSubstring(s, sub, p, n);
    printf("%s", sub);

    return 0;
}

void criarSubstring (char s[], char sub[], int p, int n) {
    int i, j;
    if ((p < 0) || (n <= 0)) {
        printf("p ou n invalidos");
    } else {
        for (i = 0, j = p; (s[j] != '\0') && (i < n); i++, j++) {
            sub[i] = s[j];
        }
    }
    sub[i] = '\0';
}