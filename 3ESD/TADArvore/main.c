#include "TADArvore.h"
#include <stdio.h>

int main() {
    tArvore *arvF1 = criarNoArvore(NULL, NULL, 50);
    tArvore *arvF2 = criarNoArvore(NULL, NULL, 60);
    tArvore *arvRaiz = criarNoArvore(arvF1, arvF2, 40);

    percorrerArvore(arvRaiz);
    
    return 0;
}