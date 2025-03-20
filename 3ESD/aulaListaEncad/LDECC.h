typedef struct tnode tNoDE;
  
typedef struct tlistade tListaDE;


tListaDE * listaDE_cria (int ehClassif,int temRepet);

int listaDE_ehclassif (tListaDE * pL);
int listaDE_temRepet (tListaDE * pL);
int listaDE_isVazia(tListaDE* pL);
int listaDE_inclui(tListaDE *pL, int inf);
int listaDE_exclui(tListaDE *pL, int inf);
void listaDE_imprime(tListaDE* pL);