// Desenvolver uma função que, dada uma string
// s, crie uma substring que inicie na posição p de
// s e contenha n caracteres.
// Observações: se p e/ou n forem inválidos, a
// substring será vazia; ii) se s não possuir n
// caracteres além de p, a substring a ser criada
// começará em p e terminará no final de s.

#include <stdio.h>

void substring(int tamanho, int posicao, char s[], char sub[tamanho]) {
  int i, j, cont = 0;
  for (i = posicao, j = 0; s[i] && (j < tamanho); i++, j++) {
    sub[j] = s[i];
  }
  sub[j] = '\0';
}

int main() {
  int p, n;
  printf("Selecione a posicao: ");
  scanf("%d", &p);
  printf("Selecione a quantidade: ");
  scanf("%d", &n);
  char s[] = "ALGORITMO", sub[n];
  substring(n, p, s, sub);
  puts(sub);

  return 0;
}