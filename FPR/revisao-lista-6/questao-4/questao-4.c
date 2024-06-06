// Uma instituição de ensino armazenou sob a forma de
// vetores de structs, um por turno (manhã e noite), os
// dados das diversas disciplinas (código, nome e a
// quantidade de alunos inscritos).

// Considerando a existência dos vetores vetManha e
// vetNoite, pede-se a implementação de uma função que
// gere um novo vetor, do mesmo tipo, que armazene,
// para cada disciplina ministrada na instituição, o total de
// alunos nela inscritos (somando as quantidades
// matriculadas em cada turno).

#include <stdio.h>
#include <string.h>
#define TAM 4

typedef struct {
    int codigo;
    char nome[50];
    int inscritos;
} TDisciplina;



void criarVetores (TDisciplina vetManha[], TDisciplina vetNoite[], int vetSoma[], int disciplinas);
void preencherVetores (TDisciplina vetManha[], TDisciplina vetNoite[]);
void printarDisciplina (TDisciplina vetManha, int vetDisciplina);

int main (void) {
    TDisciplina vetManha[TAM], vetNoite[TAM];
    int vetSoma[TAM], disciplinas = TAM;

    preencherVetores(vetManha, vetNoite);
    criarVetores(vetManha, vetNoite, vetSoma, disciplinas);
    
    return 0;
}

void criarVetores (TDisciplina vetManha[], TDisciplina vetNoite[], int vetSoma[], int disciplinas) {
    int i, j;
    printf("Total de alunos:\n\n");
    for (i = 0; i < disciplinas; i++) {
        for (j = 0; vetManha[i].codigo != vetNoite[j].codigo; j++);
        vetSoma[i] = vetManha[i].inscritos + vetNoite[j].inscritos; 
        printarDisciplina(vetManha[i], vetSoma[i]);
    }
    printf("\n");
}

void printarDisciplina (TDisciplina vetManha, int vetDisciplina) {
    printf("%s: %d ", vetManha.nome, vetDisciplina);
    printf("\n");
}

void preencherVetores (TDisciplina vetManha[], TDisciplina vetNoite[]) {
    vetManha[0].codigo = 2;
    strcpy(vetManha[0].nome, "SOP");
    vetManha[0].inscritos = 34;

    vetManha[1].codigo = 0;
    strcpy(vetManha[1].nome, "MAC");
    vetManha[1].inscritos = 42;

    vetManha[2].codigo = 3;
    strcpy(vetManha[2].nome, "REQ");
    vetManha[2].inscritos = 26;

    vetManha[3].codigo = 1;
    strcpy(vetManha[3].nome, "FAC");
    vetManha[3].inscritos = 30;

    vetNoite[0].codigo = 0;
    strcpy(vetNoite[0].nome, "MAC");
    vetNoite[0].inscritos = 24;

    vetNoite[1].codigo = 1;
    strcpy(vetNoite[1].nome, "FAC");
    vetNoite[1].inscritos = 35;

    vetNoite[2].codigo = 2;
    strcpy(vetNoite[2].nome, "SOP");
    vetNoite[2].inscritos = 18;

    vetNoite[3].codigo = 3;
    strcpy(vetNoite[3].nome, "REQ");
    vetNoite[3].inscritos = 21;
}