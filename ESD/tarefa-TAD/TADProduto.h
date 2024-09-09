typedef struct produto tProduto;
#include "TADUnidade.h"

tProduto* prd_criar (char* id, char* codigo, float preco);

void prd_libera (tProduto* prd);

char* prd_getProduto (tProduto* prd);

char* prd_getId (tProduto* prd);

char* prd_getCodigo (tProduto* prd);

char* prd_getPreco (tProduto* prd);

char* prd_getQuant (tProduto* prd);

void prd_setId (tProduto* prd, char* novoId);

void prd_setCodigo (tProduto* prd, char* novoCodigo);

void prd_setPreco (tProduto* prd, float novoPreco);

void prd_setQuant (tProduto* prd, int novaQuant);

void prd_exibeProduto (tProduto* prd);

void prd_exibeID (tProduto* prd);

void prd_exibeCodigo (tProduto* prd);

void prd_exibePreco (tProduto* prd);

void prd_exibeQuant (tProduto* prd);

int prd_semelhante (tProduto* prd1, tProduto* prd2);

void prd_reajuste (tProduto* prd, float valor);

