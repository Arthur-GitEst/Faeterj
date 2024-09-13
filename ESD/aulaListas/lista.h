typedef struct tipo_lista tLista; 
/*cria lista vazia*/ 
tLista * cria_lista_vazia(int maximo,int classif, int repet) ;
//lista está vazia? 
int lista_vazia(tLista *pl);
//lista está cheia? 
int lista_cheia(tLista *pl);
//lista com repetição? 
int lista_repet(tLista *pl);
//lista classificada? 
int lista_classif(tLista *pl);
//percorre a lista 
void percorre(tLista *pl) ;
//inclui um item na lista: verifica caso repetição e classificação
int inclui(tLista *pl, int valor) ;

int busca_des_srep(tLista *pl,int chave,int *pos);

int busca_bin(tLista*pl, int chave, int *pos);

