// Implementar uma função que remova todas as
// ocorrências de determinado caracter em uma
// string.

#include <stdio.h>
#include <string.h>

void removerocorrencias (char s[], char c);

int main () {
    char s[] = "arara";

    removerocorrencias(s, 'r');
    printf("%s", s);
    
    return 0;
}

void removerocorrencias (char s[], char c) {
    int i, j;
    for (i = 0; s[i]; i++) {
        if (s[i] == c) {
            for (j = i; s[j]; j++) {
                s[j] = s[j+1];
            }
        }
    }
}