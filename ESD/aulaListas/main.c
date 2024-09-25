#include <stdio.h>
#include "lista.h"

int main () {
    tLista* lista;
    
    lista = cria_lista_vazia(10, 1, 1);
    
    lista_inclui(lista, 2);
    lista_inclui(lista, 2);
    lista_inclui(lista, 3);
    lista_inclui(lista, 3);
    lista_inclui(lista, 4);
    lista_inclui(lista, 4);

    lista_remover(lista, 3);
    
    lista_percorrer(lista);
    
    return 0;
}