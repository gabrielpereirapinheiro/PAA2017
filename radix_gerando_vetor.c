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
void show_time(clock_t inicio,clock_t fim)
{	
	printf("\n\n============================================\n");
	printf("O tempo de execucao foi : %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
	printf("============================================\n");
}

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

void altera_posicao(int contagem[],int vetor[],int vetor_aux[],int vetorOriginal[],int vetor_aux2[],int tamanho,int exp)
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
		vetor_aux2[posicao-1]=vetorOriginal[i];
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
void troca_vetor(int vetor[],int vetor_aux[],int vetorOriginal[],int vetor_aux2[],int tamanho)
{
	int i;
	for (i = 0; i < tamanho; i++)
    {
        vetor[i] = vetor_aux[i];
        vetorOriginal[i] = vetor_aux2[i];
    }
} 
void radixsort(unsigned int vetor[],unsigned int vetorOriginal[], int tamanho) 
{
    int i;
    int *vetor_aux;
    int *vetor_aux2;
    int exp = 1;
    int maior;

    vetor_aux = (int *)calloc(tamanho, sizeof(int));
    vetor_aux2 = (int *)calloc(tamanho,sizeof(int));

    maior = acha_maior(vetor,tamanho);
 
    while (maior/exp > 0) 
    {
        int contagem[10] = { 0 };

        algarismo(contagem,vetor,tamanho,exp);

        soma_anteriores(contagem);

        altera_posicao(contagem,vetor,vetor_aux,vetorOriginal,vetor_aux2,tamanho,exp);

        troca_vetor(vetor,vetor_aux,vetorOriginal,vetor_aux2,tamanho);

    	exp *= 10;
    }

    free(vetor_aux);
}

void vetor_passo(unsigned int vetor_aux[],int unsigned vetor[],int mul,int tamanho)
{
	int i;
	unsigned int a = 0x000000ff;//255
	unsigned int b = 65280;//0x00f0
	unsigned int c = 16711680;
	unsigned int d = 4278190080; 
	if(mul==1)
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor_aux[i] = vetor[i] & a;
		}
	}
	if (mul==2)
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor_aux[i] = vetor[i] & b;
		}
	}
	if (mul==3)
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor_aux[i] = vetor[i] & c;
		}
	}
	if (mul==4)
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor_aux[i] = vetor[i] & d;
		}
	}
}

void ordena(int vetor[],int tamanho, int passos)
{
	if(passos=4)
	{
		unsigned int  vetor_bin[1000000];

		vetor_passo(vetor_bin,vetor,1,tamanho);
		radixsort(vetor_bin,vetor,tamanho);
	
		vetor_passo(vetor_bin,vetor,2,tamanho);
		radixsort(vetor_bin,vetor,tamanho);

		vetor_passo(vetor_bin,vetor,3,tamanho);
		radixsort(vetor_bin,vetor,tamanho);

		vetor_passo(vetor_bin,vetor,4,tamanho);
		radixsort(vetor_bin,vetor,tamanho);
	}
	if(passos=1)
	{
		radixsort(vetor,vetor,tamanho);
	}
}

void gera_vetor(int vetor[],int tamanho,int opcao)
{
	if (opcao==1)
	{
		for (long int i = 0; i < tamanho; ++i)
		{
			vetor[i]=tamanho-i;
		}
	}
	if(opcao==2)
	{
		for (long int i= 0; i < tamanho; ++i)
		{
			vetor[i]=1;
		}
	}
}

int recebe_do_usuario()
{
	int qnt;

	printf("======================\n      RADIX SORT     \n====================== \n");
	printf("\n\nEscolha o valor do R entre 8 ou 32 bits");
	printf("\n->");
	scanf("%d",&qnt);

	while(qnt!=8 && qnt!=32)
	{
		printf("\nEscolha entre 8 ou 32\n");
		printf("->");
		scanf("%d",&qnt);
	}
	if(qnt==8)
	{
		qnt = 4;
	}
	else
	{
		qnt = 1;
	}

	return qnt;
}
int recebe_do_usuario_opcao()
{
	int opcao;

	printf("\nEscolha o estado do vetor inicial:");
	printf("\n1 - Decrescente\n");
	printf("2 - Todo preenchido com um numero\n");
	printf("-> ");
	scanf("%d",&opcao);

	while(opcao!=1 && opcao!=2)
	{
		printf("Escolha entre 1 ou 2\n->");
		scanf("%d",&opcao);
	}
	return opcao;
}


int main()
{	
	//Contador
	int i=0;

	//Tamanho maximo do vetor
	unsigned int vetor[1000000];

	//Tamanho e t-1 para nao acessar possicoes invalidas
	int size = 1000000;

	int passos;
	passos = recebe_do_usuario();
	int opcap_vetor;
	opcap_vetor = recebe_do_usuario_opcao();
	
	//Funcao que gera vetor decrescente
	gera_vetor(vetor,size,opcap_vetor);

	//Inicia o tempo
	clock_t inicio = clock();//Ordena , funcao que ira chamar o radix

	//Chama Radix
	ordena(vetor,size,passos);

	//Variavel para fim do tempo
	clock_t fim = clock();

	//Mostra vetor ordenado
	//show_vector(vetor,size);

	//Mostra o tempo
	show_time(inicio,fim);

	return 0;
}