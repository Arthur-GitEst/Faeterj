/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 12/06/2024
   
   Pilhas (encadeadas)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista P = NULL;  //representando a pilha inicialmente vazia
	int num, op;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido na pilha: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == 1)   //ou apenas: if (empilhar (&P, num))			        
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if (desempilhar (&P, &num))
			        {
			        	printf ("\n\tO valor %d foi removido da pilha!", num);
					}
					else
					{
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;

			//Topo
			case 3: //chamando a função
			        if (topo (P, &num))
			        {
			        	printf ("\n\tTopo da pilha: %d", num);
					}
					else
					{
						printf ("\n\tERRO: Pilha vazia!");
					}
					break;
					
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementação das funções
int empilhar (TLista *P, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória para o novo elemento
	aux = (TLista) malloc (sizeof(TNo));   //malloc - memory allocation
	
	//verificando se houve erro na alocação
	if (!aux)
	{
		return 0;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posição recém-alocada
		aux->valor = numero;
		
		//Passo 3: fazer o novo nó apontar para o "antigo primeiro nó"
		aux->prox = *P;
		
		//Passo 4: fazer com que *P aponte para o novo Nó
		*P = aux;
		
		return 1;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha possui elementos
	if (*P)
	{
		//aux guardando o endereço do nó que será removido
		aux = *P;   
			
		//fazendo *P apontar para o "antigo segundo nó"
		*P = aux->prox;       //ou   *P = (*P)->prox;
			
		//armazenando no parâmetro 'numero' o valor que estava no topo da pilha
		*numero = aux->valor;
		
		//liberando a memória do nó a ser removido
		free (aux);			
		
		return 1;
	} 
	else
	{
		return 0;
	}
}

int topo (TLista P, int *t)
{
	//verificando se a pilha possui elementos
	if (P)
	{
		//armazenando em 't' o valor que está no topo da pilha
		*t = P->valor;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}