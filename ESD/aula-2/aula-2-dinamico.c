#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct p {
    char *nome;
    int idade;
    char *email;
};

typedef struct p tPessoa;

void preencherPessoa (tPessoa *pPessoa) {
  char aux[100];
  int idadeDada;

  printf("Digite o nome: ");
  fflush(stdin);
  scanf("%s", aux);
  *pPessoa->nome = (char*)malloc(strlen(aux) + 1);
  strcpy(pPessoa->nome, aux);

  printf("Digite o email: ");
  fflush(stdin);
  scanf("%s", aux); 
  pPessoa->email = (char*)malloc(strlen(aux) + 1);
  strcpy(pPessoa->email, aux);

  printf("Digite a idade: ");
  fflush(stdin);
  scanf("%d", &idadeDada);
  pPessoa->idade = idadeDada;
}

tPessoa copia (tPessoa p1) {
    tPessoa p2;
    p2.nome = (char*)malloc(strlen(p1.nome) + 1);
    p2.email = (char*)malloc(strlen(p1.email) + 1);
    strcpy(p2.nome, p1.nome);
    strcpy(p2.email, p1.email);
    p2.idade = p1.idade;
    return p2;
}

int main () {
  tPessoa *vPessoa[30];
  int i;

  for (i = 0; i < 3; i++) {
    printf("\nPessoa %d\n", i + 1);
    preencherPessoa(&vPessoa[i]);
  }

  printf("%s\n", vPessoa[1]->nome);
  printf("%s\n", vPessoa[1]->email);
  printf("%d\n", vPessoa[1]->idade);

  return 0;
}