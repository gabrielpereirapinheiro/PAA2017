/*PROJETO E ANALISE DE ALGORITMOS 2017-1
 *ALUNO:GABRIEL PEREIRA PINHEIRO
 *MATRICULA: 14/0020764
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*Funcao que mostra o tempo de execucao total do programa
 *Recebe: o tempo inicio e o tempo final do programa
 *Retorna: 
*/
void show_time(time_t inicio,time_t fim)
{	
	printf("O tempo de execucao em segundos é %f\n", difftime(fim, inicio));
}

void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}
int main()
{
	//Variaveis que irao marcar o tempo decorrido
	time_t inicio, fim;

	inicio = time(NULL);



	int vetor[10];

	for (int i = 0; i < 10; ++i)
	{
		vetor[i]= i *4;

		if(i==4)
		{
			vetor[i]=0;
		}
		if(i==1)
		{
			vetor[i]=10;
		}
	}

	radixsort(vetor,10);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",vetor[i] );
	}





	fim = time(NULL);

	show_time(inicio,fim);

	return 0;
}