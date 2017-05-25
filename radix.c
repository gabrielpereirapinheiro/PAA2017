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

int main()
{
	//Variaveis que irao marcar o tempo decorrido
	time_t inicio, fim;

	inicio = time(NULL);

	sleep(2);

	fim = time(NULL);

	show_time(inicio,fim);
	return 0;
}