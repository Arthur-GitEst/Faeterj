// Suponha que não existissem as funções strlen,
// strcpy, strcat e strcmp. Pede-se, então, a
// implementação de funções que tenham o
// mesmo objetivo daquelas.

#include <stdio.h>

int strLen (char s[]);
void strCpy (char s1[], char s2[]);
void strCat (char s1[], char s2[]);

int main () {
    char s1[] = "Arthur e um ", s2[] = "Aluno";

    // printf("%d", strLen(s1));

    // strCpy(s2, s1);
    // printf("%s", s2);

    strCat(s1, s2);
    printf("%s", s1);
    
    return 0;
}

int strLen (char s[]) {
    int i, cont = 0;
    for (i = 0; s[i] != '\0'; i++) {
        cont++;
    }
    return cont;
}

void strCpy (char s2[], char s1[]) {
    int i, j;
    for (i = 0, j = 0; s1[i] != '\0'; i++, j++) {
        s2[j] = s1[i];
    }
    s2[j] = '\0';
}

void strCat (char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++);
    for (j = 0; s2[j] != '\0'; j++, i++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
}
