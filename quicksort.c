/*PROJETO E ANALISE DE ALGORITMOS 2017-1
 *ALUNO:GABRIEL PEREIRA PINHEIRO
 *MATRICULA: 14/0020764
*/

# include <stdio.h>
#include <stdlib.h>

//Funcao que ira ordenadr
void quick_sort(int vetor[],int primeiro,int ultimo)
{	
	//Iniciando variaveis
	int inicio,fim,pivo,aux;
	//Definir parametros variaveis inferior
	inicio = primeiro;
	//Definir parametro variavel superior
	fim = ultimo;
	//Pivo e a metade
	pivo = vetor[(inicio+fim)/2];

	while(inicio<=fim)
	{
		while(vetor[inicio] < pivo)
		{
			inicio=inicio+1;
		}
		while(vetor[fim]>pivo)
		{
			fim=fim-1;
		}
		if(inicio<=fim)
		{
			aux = vetor[inicio];
			vetor[inicio]=vetor[fim];
			vetor[fim]=aux;
			inicio = inicio + 1;
			fim = fim - 1;
		}
	}
	if (fim>primeiro)	
	{
		quick_sort(vetor,primeiro,fim);
	}
	if (inicio<ultimo)
	{
		quick_sort(vetor,fim+1,ultimo);
	}
}

//Funcao que ira mostrar vetor na tela
void show_vector(int vetor[],int tamanho)
{	//Contador
	int i=0;
	//Pecorrer todo o vetor
	while(tamanho>i)
	{
		//Imprime
		printf("%d\n",vetor[i]);
		//Incremente contador
		i++;
	}
}


//Funcao principal
int main()
{
	//Variavel que ira receber a quantidade numeros
	int t;
	//Contador
	int i=0;
	//Tamanho maximo do vetor
	int vetor[1000000];

	//Numero de vezes que sera digitado um numero
	scanf("%d",&t);

	//Lendo T numeros e salvando no vetor.
	while(t>i)
	{
		scanf("%d",&vetor[i]);
		i++;
	}
	//Tamanho e t-1 para nao acessar possicoes invalidas
	int size = t -1;

	//Ordena vetor
	quick_sort(vetor,0,size);
	
	//Mostra vetor ordenado
	show_vector(vetor,t);

}