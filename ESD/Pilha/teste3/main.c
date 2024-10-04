#include "pilha.h"

int main () {
    Pilha *pilha = criaPilha();
    int dado;

    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    pop(pilha, &dado);

    exibePilha(pilha);
    
    return 0;
}