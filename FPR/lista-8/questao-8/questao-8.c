// Desenvolver uma função recursiva que, dada
// uma string, exiba-a invertida.

#include <stdio.h>
#include <string.h>

void exibirStringInvertida (char s[], int i);

int main () {
    char s[] = "arthur";

    exibirStringInvertida(s, (strlen(s) - 1));
    
    return 0;
}

void exibirStringInvertida (char s[], int i) {
    if(i >= 0) {
        printf("%c", s[i]);
        exibirStringInvertida(s, --i);
    }
}