#define MAX 3
#define MIN 2

struct noArvB *raiz;

struct noArvB *criaNo(int chave, struct noArvB *filho);

void insereNoNo(int chave, int pos, struct noArvB *no, struct noArvB *filho);

void split(int chave, int *pval, int pos, struct noArvB *no, struct noArvB *filho, struct noArvB **novoNo);

int alterarValorNoNo(int chave, int *pval, struct noArvB *no, struct noArvB **filho);

void insere(int chave);

void copiarSucessor(struct noArvB *no, int pos);

void removeValor(struct noArvB *no, int pos);

void girarDireita(struct noArvB *no, int pos);

void girarEsquerda(struct noArvB *no, int pos);

void merge(struct noArvB *no, int pos);

void ajustaNo(struct noArvB *no, int pos);

int removeValorDoNo(int chave, struct noArvB *no);

void remover (int chave, struct noArvB *no);

void busca(int chave, int *pos, struct noArvB *no);

void percorre(struct noArvB *no);



