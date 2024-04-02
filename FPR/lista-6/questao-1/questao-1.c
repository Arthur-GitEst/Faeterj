// Suponha que não existissem as funções strlen,
// strcpy, strcat e strcmp. Pede-se, então, a
// implementação de funções que tenham o
// mesmo objetivo daquelas.

#include <stdio.h>

int strlen (char s[]) {
  int cont = 0, i;
  for (i = 0; s[i]; i++) {
    cont++;
  }
  return cont;
}

void strcpy (char s2[], char s1[]) {
  int i;
  for (i = 0; s1[i]; i++) {
    s2[i] = s1[i];
  }
  s2[i] = '\0';
}

void strcat (char s1[], char s2[]) {
  int i, j;
  for (i = 0; s1[i]; i++);
  for (j = 0; s2[j]; j++) {
    s1[i] = s2[j];
    i++;
  }
  s1[i] = '\0';
}

int strcmp (char s1[], char s2[]) {
  int i, resultado = 0;
  for (i = 0; s1[i] == s2[i]; i++);
  resultado = s1[i] - s2[i];
  return resultado;
}

int main () {
  char s1[] = "Arthur ", s2[] = "Artur";
  printf ("%d", strcmp(s1, s2));
}