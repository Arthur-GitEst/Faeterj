#include "fila.h"

int main () {
    Fila *fila = criaFila();

    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);

    mostraFila(fila);
    
    return 0;
}