typedef struct no tNo; 
typedef struct fila Fila; 
Fila *criaFila(); 
int enfileirar(Fila *f, int dado);
int desenfileirar(Fila *f); 
int mostraFila(Fila *f);  // só para nossos testes
void liberaFila(Fila *f); 
int filaVazia(Fila *f);

tNo *criaNo(int valor);