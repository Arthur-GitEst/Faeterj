// Implementar uma função que remova todas as
// ocorrências de determinado caracter em uma
// string.

#include <stdio.h>

int remover(char letra, char s[]) {
  int i, j, cont = 0;
  for (i = 0; s[i]; i++) {
    if (s[i] == letra) {
      for (j = i; s[j]; j++) {
        s[j] = s[j+1];
      }
      cont++;
    }
  }
  s[i] = '\0';
  return cont;
}

int main() {
  char letra, s[] = "arara";
  int remocoes;
  printf("Digite a letra a ser removida: ");
  scanf("%s", &letra);
  remocoes = remover(letra, s);
  puts(s);
  printf("Remocoes: %d", remocoes);
}