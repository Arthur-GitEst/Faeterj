// Dada uma string s, desenvolver uma função
// que determine se s é ou não um palíndromo.
// Observação: uma string s será um palíndromo
// quando seus caracteres formarem a mesma
// sequência, independente se s é percorrida da
// esquerda para direita ou vice-versa.

#include <stdio.h>
#include <string.h>

int palindromo(char s[]) {
  int i, j;
  for (i = 0, j = (strlen(s) - 1); i < j; i++, j--) {
    if (s[i] != s[j]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char s[] = "arthur"; 
  if (palindromo(s)) {
    printf("E um palindromo");
  } else {
    printf("Nao e um palindromo");
  }
}