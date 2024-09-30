#include "LDECC.h"
#include <stdlib.h>
struct tnode {
  int id;
  struct tnode * suc;
  struct tnode * ant;
};
struct tlistade{
 tNoDE * prim;
 int temClassif,comRepet;
};
/*=======================================*/
// FUNÇÕES AUXILARES
/* busca*/

int BUSCA_SENTINELA_ou_Rapida(tListaDE * pL, int id, tNoDE** pNo);
/* cria_no*/
  
tNoDE* criaNo(int id);
/*=======================================*/


tListaDE * listaDE_cria (int ehClassif,int temRepet)
{
    tListaDE * pL=(tListaDE *) malloc (sizeof (tListaDE));
    tNoDE* p = criaNo(0); //cabeça
    p->suc = p->ant = p;
    pL->prim = p;
    pL->temClassif=ehClassif;
    pL->comRepet=temRepet;
    return pL;
  }
 
int listaDE_ehclassif (tListaDE * pL){
  return pL->temClassif;
}
int listaDE_temRepet (tListaDE * pL){
  return pL->comRepet;
}
int listaDE_isVazia(tListaDE* pL){
  return pL->prim->suc==pL->prim;
}
int listaDE_inclui(tListaDE *pL, int inf){
  tNoDE * pNovo, * pSuc;
  int sit;
  if (!listaDE_ehclassif(pL) && listaDE_temRepet(pL))
    pSuc=pL->prim->suc; // o sucessor é o cabeça
  else
    sit=BUSCA_SENTINELA_ou_Rapida (pL, inf, &pSuc);
    if (!listaDE_temRepet(pL) && sit)
      return -1;
  pNovo = criaNo(inf);
  if (pNovo ==NULL)
    return 0;
  //Nó se conecta à lista
  pNovo->suc = pSuc;
  pNovo->ant = pSuc->ant;
  //Lista incorpora o nó
  pNovo->ant->suc = pNovo;
  pNovo->suc->ant = pNovo;
  return 1;
}
int listaDE_exclui(tListaDE *pL, int inf){ 
  tNoDE * p, * pno,*paux;BUSCA_SENTINELA_ou_Rapida
 
  if (listaDE_isVazia(pL))
      return 0;
  if (!BUSCA_SENTINELA_ou_Rapida (pL, inf, &pno))
      return -1;
  
  if (!listaDE_temRepet (pL)) {// Sem repetição
    // desliga o nó da lista
    pno->ant->suc = pno->suc;
    pno->suc->ant = pno->ant;
    free (pno);
  }
  else{
    pL->prim->id=inf-1;
    if (!listaDE_ehclassif (pL)){
      
      for(p = pno;p!=pL->prim;p=p->suc)
       
        if (p->id==inf){
            pno=p;
            p->ant->suc = p->suc;
            p->suc->ant = p->ant;
            p=p->ant;
            free(pno);
            
          }
    }
    else{
      pL->prim->id=inf-1;
      paux=pno->ant;
      while(pno->id==inf){
         
          p=pno->suc;
          free(pno);
          pno=p;
      }
      paux->suc=pno;
      pno->ant=paux;
    
    }
  }
  return 1;
}

void listaDE_imprime(tListaDE* pL){
  tNoDE* p = pL->prim->suc;
  
  while (p!=pL->prim) {
    printf("%d ", p->id);
    p = p->suc;
  }BUSCA_SENTINELA_ou_Rapida

  puts("");
  
  return;
}

int BUSCA_SENTINELA_ou_Rapida (tListaDE *pL, int chv, tNoDE ** pno){
  tNoDE *p;
  pL->prim->id = chv; /* Coloca chv na cabeça */
  if (listaDE_ehclassif(pL))
    for (p = pL->prim->suc; p->id <chv; p = p->suc);
  else
    for (p = pL->prim->suc; p->id !=chv; p = p->suc);
  (*pno) = p;
  
  return ((p!=pL->prim) && (p->id == chv));
    
}

tNoDE* criaNo(int id){
  tNoDE* no = (tNoDE*) malloc(sizeof(tNoDE));

  no->id = id;
  no->suc = NULL;
  no->ant=NULL;

  return no;
}