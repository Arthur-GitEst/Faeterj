#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct tipo_lista 
{ 
    int* vnos; 
    int qtnos; 
    int maximo; 
    int classificada;  
    int repeticao; 
}; 

void lista_exibe (int valor);

int lista_busca_des (tLista *lista,int chave,int *pos);
int lista_busca_bin (tLista *lista, int chave, int *pos) ;


tLista * cria_lista_vazia (int maximo,int classif, int repet) {
    tLista * lista= (tLista*) malloc(sizeof(tLista));
	lista->vnos=(int *) malloc(sizeof(int) * maximo);
	lista->qtnos = 0; 
    lista->maximo= maximo; 
    lista->classificada=classif; 
    lista->repeticao=repet; 
    return lista;
} 

int lista_vazia (tLista *lista){ 
    return (lista->qtnos == 0); 
}

int lista_cheia (tLista *lista){ 
    return (lista->qtnos == lista->maximo); 
} 

int lista_repet (tLista *lista){ 
    return (lista->repeticao == 1); 
} 

int lista_classif (tLista *lista){ 
    return (lista->classificada == 1); 
} 

void lista_percorrer (tLista *lista) { 
    int i; 
    for(i = 0; i < lista->qtnos; i++) 
        lista_exibe(lista->vnos[i]); 
} 

//inclui um item na lista: verifica caso repetição e classificação
int lista_inclui (tLista *lista, int valor) {
    int pos, st;
    
    if (lista_cheia(lista)) {
        return 0;
    }
    
    if (lista_repet(lista) == 1 && lista_classif == 0) {
        pos = lista->qtnos;
        st = 0;
    } else if (lista_classif(lista) == 1) {
        st = lista_busca_bin(lista, valor, &pos);
        if (lista_repet(lista)) {
            st = 0;
        } 
    } else {
        st = lista_busca_des(lista, valor, &pos);
    }

    if (st == 1) {
        return -1;
    }

    if (pos < lista->qtnos) {
        int qt = lista->qtnos - pos;
        memcpy(lista->vnos + pos + 1, lista->vnos + pos, qt * sizeof(int));
    }
    lista->vnos[pos] = valor;
    lista->qtnos++;
    return 1;
}

int lista_remover (tLista *lista, int valor) {
    int pos, st, i;

    //verifica se a lista está vazia
    if (lista_vazia(lista)) {
        return 0;
    }

    //com repeticção e sem classificação
    if (lista_repet(lista) == 1 && lista_classif(lista) == 0) {
        //buscando o valor
        st = lista_busca_des(lista, valor, &pos);
        
        while (pos < lista->qtnos) {
            if (lista->vnos[pos] == valor) {
                memcpy(&lista->vnos[pos])
            }
        }

        return 1;
    } else if (lista_classif(lista) == 1) {
        //buscando o valor
        st = lista_busca_bin(lista, valor, &pos);

        if (st) {
            //com repetição e classificação
            if (lista_repet(lista) == 1) {
                //repete enquanto o valor existir na lista
                while (lista->vnos[pos] == valor && pos < lista->qtnos - 1) {
                    //removendo o valor
                    for (i = pos; i < lista->qtnos - 1; i++) {
                        lista->vnos[i] = lista->vnos[i + 1];
                    }

                    //atualizando a quantidade de nós
                    lista->qtnos--;
                }
            } 
            //com classificação e sem repetição
            else {
                //removendo o valor
                for (i = pos; i < lista->qtnos - 1; i++) {
                    lista->vnos[i] = lista->vnos[i + 1];
                }

                lista->qtnos--;
            }
            return 1;
        }
        //retorno caso o valor não exista
        return -1;
    }
    //sem repetição e classificação
    else {
        //buscando o valor
        st = lista_busca_des(lista, valor, &pos);

        if (st) {
            //removendo o valor
            for (i = pos; i < lista->qtnos - 1; i++) {
                lista->vnos[i] = lista->vnos[i + 1];
            }

            lista->qtnos--;

            return 1;
        }

        //retorno caso o valor não exista
        return -1;
    }
}

//FUNÇÔES AUXILIARES

//exibe item 
void lista_exibe(int valor) { 
    printf("\n%d",valor);
} 

int lista_busca_des(tLista *lista,int chave,int *pos){ 
    int i; 
    for(i=0; (i<lista->qtnos)&&(lista->vnos[i]!=chave); i++); 
    (*pos) = i; 
    return(i < lista->qtnos); 
} 

int lista_busca_bin(tLista*lista, int chave, int *pos) 
{
    int inicio = 0;
    int meio;
    int fim= lista->qtnos-1;
    int achou = 0; 
    while((inicio <= fim) && (!achou)) { 
        meio = (inicio + fim) / 2; 
        if(lista->vnos[meio] == chave) 
            achou = 1; 
        else if(lista->vnos[meio] > chave) 
            fim=meio-1; 
        else 
            inicio= meio+1; 
    } 
    if(achou) { 
        (*pos) = meio; 
    } 
    else 
        (*pos) = inicio; 
    return achou; 
} 
