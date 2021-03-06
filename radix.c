/*PROJETO E ANALISE DE ALGORITMOS 2017-1
 *ALUNO:GABRIEL PEREIRA PINHEIRO
 *MATRICULA: 14/0020764
*/

#include <stdio.h>
#include <stdlib.h>

int acha_maior(int vetor[],int tamanho)
{
	int i;
	int maior=vetor[0];

	for (i = 0; i < tamanho; i++) 
    {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    return maior;
}

void algarismo(int contagem[],int vetor[],int tamanho,int exp)
{
	int i;
	int numero;
	for (i = 0; i < tamanho; i++)
	{
    	numero = (vetor[i]/exp)%10;
    	contagem[numero]=contagem[numero] + 1;
    }
}

void soma_anteriores(int contagem[])
{
	int i;
	for (i = 1; i < 10; i++)
    {
        contagem[i] = contagem[i] + contagem[i-1];
    }
}

void altera_posicao(int contagem[],int vetor[],int vetor_aux[],int tamanho,int exp)
{
	int posicao;
	int aux;
	int i;

	for(i= tamanho-1;i>=0;i--)
	{
		aux = (vetor[i]/exp)%10;
		
		posicao = contagem[aux];

		contagem[aux]=  posicao-1;

		vetor_aux[posicao-1]=vetor[i];
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
void troca_vetor(int vetor[],int vetor_aux[],int tamanho)
{
	int i;
	for (i = 0; i < tamanho; i++)
    {
        vetor[i] = vetor_aux[i];
    }
}

void radixsort(int vetor[], int tamanho) 
{
    int i;
    int *vetor_aux;
    int exp = 1;
    int maior;

    vetor_aux = (int *)calloc(tamanho, sizeof(int));

    maior = acha_maior(vetor,tamanho);
 
    while (maior/exp > 0) 
    {

        int contagem[10] = { 0 };

        algarismo(contagem,vetor,tamanho,exp);

        soma_anteriores(contagem);

        altera_posicao(contagem,vetor,vetor_aux,tamanho,exp);

        troca_vetor(vetor,vetor_aux,tamanho);

    	exp *= 10;
    }

    free(vetor_aux);
}


int main()
{

	//Variavel que ira receber a quantidade numeros
	int t;
	//Contador
	int i=0;
	//Tamanho maximo do vetor
	unsigned int vetor[1000000];

	//Numero de vezes que sera digitado um numero
	scanf("%d",&t);

	//Lendo T numeros e salvando no vetor.
	while(t>i)
	{
		scanf("%d",&vetor[i]);
		i++;
	}
	//Tamanho e t-1 para nao acessar possicoes invalidas
	int size = t ;

	//Ordena
	radixsort(vetor,size);

	//Mostra vetor ordenado
	show_vector(vetor,t);

	return 0;
}