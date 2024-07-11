/* FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 12/06/2024
   
   Filas (encadeadas)
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista F = NULL, U = NULL;  //representando a fila inicialmente vazia
	int num, op;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido na fila: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (enfilar (&F, &U, num) == 1)   //ou apenas: if (enfilar (&F, &U, num))			        
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if (desenfilar (&F, &U, &num))
			        {
			        	printf ("\n\tO valor %d foi removido da fila!", num);
					}
					else
					{
						printf ("\n\tERRO: Fila vazia!");
					}
					break;

			//Primeiro
			case 3: //chamando a função
			        if (primeiro (F, &num))
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d", num);
					}
					else
					{
						printf ("\n\tERRO: Fila vazia!");
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
int enfilar (TLista *F, TLista *U, int numero)
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
		
		//fazendo o campo 'prox' do novo nó apontar para NULL (uma vez que será o últim da fila)
		aux->prox  = NULL;
		
		//verificando se existem elementos na fila
		if (*F)  //poderia também ser:   if (*U)
		{
			//fazendo o campos 'prox' do último da fila apontar para o novo nó
			(*U)->prox = aux;
		}
		else
		{
			//atualizando o 'F', de forma a apontar para o novo nó
			*F = aux;
		}
		
		//atualizando 'U'
		*U = aux;   //ou:   *U = (*U)->prox;
		
		return 1;
	}
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a fila possui elementos
	if (*F)
	{
		//aux guardando o endereço do nó que será removido
		aux = *F;   
			
		//fazendo *F apontar para o "antigo segundo nó"
		*F = aux->prox;       //ou   *F = (*F)->prox;
		
		//verificando se a fila se tornou vazia
		if (!(*F))
		{
			*U = NULL;
		}	
		
		//armazenando no parâmetro 'numero' o valor que era o primeiro da fila
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

int primeiro (TLista F, int *p)
{
	//verificando se a fila possui elementos
	if (F)
	{
		//armazenando em 'p' o primeiro valor da fila
		*p = F->valor;
		
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
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
