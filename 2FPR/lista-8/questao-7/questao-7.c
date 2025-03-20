// Desenvolver uma função recursiva que
// determine o número de caracteres comuns
// entre duas strings s1 e s2.

#include <stdio.h>
#include <string.h>

int caracteresComuns (char s1[], char s2[], int valorS1, int valorS2);

int main () {
    char s1[] = "arthur", s2[] = "arthur";
    int cont = caracteresComuns(s1, s2, 0, 0);

    printf("%d letras sao repetidas", cont);
    
    return 0;
}

int caracteresComuns (char s1[], char s2[], int valorS1, int valorS2) {
    if (s1[valorS1] == '\0' || s2[valorS2] == '\0') {
        return 0;
    }
    if (s1[valorS1] == s2[valorS2]) {
        return 1 + (caracteresComuns(s1, s2, valorS1+1, valorS2+1));
    } else {
        return caracteresComuns(s1, s2, valorS1+1, valorS2+1);
    }
}