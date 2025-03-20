typedef struct tipo_lista tLista; 
/*cria lista vazia*/ 
tLista * cria_lista_vazia (int maximo,int classif, int repet) ;
//lista está vazia? 
int lista_vazia (tLista *lista);
//lista está cheia? 
int lista_cheia (tLista *lista);
//lista com repetição? 
int lista_repet (tLista *lista);
//lista classificada? 
int lista_classif (tLista *lista);
//percorre a lista 
void lista_percorrer (tLista *lista) ;
//inclui um item na lista: verifica caso repetição e classificação
int lista_inclui (tLista *lista, int valor);
int lista_remover (tLista *lista, int valor);

int lista_busca_des (tLista *lista,int chave,int *pos);

int lista_busca_bin (tLista*lista, int chave, int *pos);

