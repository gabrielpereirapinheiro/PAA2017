/*PROJETO E ANALISE DE ALGORITMOS 2017-1
 *ALUNO:GABRIEL PEREIRA PINHEIRO
 *MATRICULA: 14/0020764
*/

# include <stdio.h>
#include <stdlib.h>

void quick_sort(int vetor[],int primeiro,int ultimo)
{
	int inicio,fim,pivo,aux;
	inicio = primeiro;
	fim = ultimo;
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

void show_vector(int vetor[],int tamanho)
{
	int i=0;
	while(tamanho>i)
	{
		printf("%d\n",vetor[i]);
		i++;
	}
}

int main()
{
	int t;
	int i=0;
	int vetor[1000000];

	//Numero de vezes que sera digitado um numero
	scanf("%d",&t);

	//Lendo T numeros e salvando no vetor.
	while(t>i)
	{
		scanf("%d",&vetor[i]);
		i++;
	}
	int size = t -1;
	quick_sort(vetor,0,size);
	show_vector(vetor,t);

}