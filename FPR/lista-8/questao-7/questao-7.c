// Desenvolver uma função recursiva que
// determine o número de caracteres comuns
// entre duas strings s1 e s2.

#include <stdio.h>
#include <string.h>

int caracteresComuns (char s1[], char s2[], int valorS1, int valorS2, int cont);

int main () {
    char s1[] = "arthur", s2[] = "ruhtra";
    int cont = 0;

    printf("%d letras sao repetidas", caracteresComuns(s1, s2, 0, 0, cont));
    
    return 0;
}

int caracteresComuns (char s1[], char s2[], int valorS1, int valorS2, int cont) {
    if ((valorS1 < strlen(s1)) && (valorS2 < strlen(s2))) {
        if (s1[valorS1] == s2[valorS2]) {
            cont++;
            caracteresComuns(s1, s2, valorS1+1, valorS2+1, cont);
        } else {
            caracteresComuns(s1, s2, valorS1+1, valorS2+1, cont);
        }
    } else {
        return cont;
    }
}