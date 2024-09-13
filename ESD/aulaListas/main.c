#include <stdio.h>
#include "lista.h"

int main () {
    tLista* lista;
    
    lista = cria_lista_vazia(10, 1, 1);
    
    inclui(lista, 2);
    inclui(lista, 3);
    
    percorre(lista);
    
    return 0;
}