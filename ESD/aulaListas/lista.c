#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* Em seguida, um tipo para a lista */ 
struct tipo_lista 
{ 
    int* vnos; 
    int qtnos; 
    int maximo; 
    int classificada; // 1: classificada 0: não classificada 
    int repeticao; // 1: com repetição 0: sem repetição 
}; 
//////////////////////////////////////////
//FUNÇÔES AUXILIARES

//exibe item 
void exibe(int valor);

//Busca DESORDENADA sem repetição 
int busca_des_srep(tLista *pl,int chave,int *pos);
//Busca BINÁRIA 
int busca_bin(tLista *pl, int chave, int *pos) ;
//////////////////////////////////////////////////


/*cria lista vazia*/ 
tLista * cria_lista_vazia(int maximo,int classif, int repet) {
    tLista * pl= (tLista*) malloc(sizeof(tLista));
	pl->vnos=(int *) malloc(sizeof(int) * maximo);
	pl->qtnos = 0; 
    pl->maximo= maximo; 
    pl->classificada=classif; 
    pl->repeticao=repet; 
    return pl;
} 
//lista está vazia? 
int lista_vazia(tLista *pl){ 
    return ( pl->qtnos == 0); 
}
//lista está cheia? 
int lista_cheia(tLista *pl){ 
    return ( pl->qtnos == pl->maximo); 
} 
//lista com repetição? 
int lista_repet(tLista *pl){ 
    return ( pl->repeticao == 1); 
} 
//lista classificada? 
int lista_classif(tLista *pl){ 
    return ( pl->classificada == 1); 
} 
//percorre a lista 
void percorre (tLista *pl) { 
    int i; 
    for(i = 0; i < pl->qtnos; i++) 
        exibe(pl->vnos[i]); 
} 

//inclui um item na lista: verifica caso repetição e classificação
int inclui (tLista *pl, int valor) {
    int pos, st;
    
    if (lista_cheia(pl)) {
        return 0;
    }
    
    if (lista_repet(pl) == 1 && lista_classif == 0) {
        pos = pl->qtnos;
        st = 0;
    } else if (lista_classif(pl) == 1) {
        st = busca_bin(pl, valor, &pos);
        if (lista_repet(pl)) {
            st = 0;
        } 
    } else {
        st = busca_des_srep(pl, valor, &pos);
    }

    if (st == 1) {
        return -1;
    }

    if (pos < pl->qtnos) {
        int qt = pl->qtnos - pos;
        memcpy(pl->vnos + pos + 1, pl->vnos + pos, qt * sizeof(int));
    }
    pl->vnos[pos] = valor;
    pl->qtnos++;
    return 1;
}

//FUNÇÔES AUXILIARES

//exibe item 
void exibe(int valor) { 
    printf("\n%d",valor);
} 

//Busca DESORDENADA sem repetição 
int busca_des_srep(tLista *pl,int chave,int *pos){ 
    int i; 
    for(i=0; (i<pl->qtnos)&&(pl->vnos[i]!=chave); i++); 
    (*pos) = i; 
    return(i < pl->qtnos); 
} 
//Busca BINÁRIA 
int busca_bin(tLista*pl, int chave, int *pos) 
{
    int inicio = 0;
    int meio;
    int fim= pl->qtnos-1;
    int achou = 0; 
    while((inicio <= fim) && (!achou)) { 
        meio = (inicio + fim) / 2; 
        if(pl->vnos[meio] == chave) 
            achou = 1; 
        else if(pl->vnos[meio] > chave) 
            fim=meio-1; 
        else 
            inicio= meio+1; 
    } 
    if(achou) { 
        (*pos) = meio; 
        /*
        if (lista_repet(pl)) { 
            do { 
                (*pos)--; 
            }while ((*pos)>=0) && (pl->vnos[(*pos)].chave ==chave); (*pos)++; 
        } 
        */
    } 
    else 
        (*pos) = inicio; 
    return achou; 
} 
