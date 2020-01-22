#include<stdio.h>
#include<stdlib.h>

void printArray(int *array, int inicio, int fim){
	printf("====================\n");
	for(int i = inicio, j = 0; i <= fim; i++, j++){
		printf("vetor[%d] - %d\n", j, array[i]);
	}
	printf("====================\n");
}

void merge(int *array, int inicio, int meio, int fim) 
{
	int i, j, k, *auxiliar;
	
	i = inicio; 
	j = meio + 1;
	k = 0; 
	
	auxiliar = (int *) malloc (sizeof(int) * ((fim - inicio) + 1));
	while(i <= meio && j <= fim)
	{
		if(array[i] < array[j])
		{
			auxiliar[k] = array[i];
			i++;
		}
		else
		{
			auxiliar[k] = array[j];
			j++;
		}
		k++;
	}
	
	while(i <= meio)
	{
		auxiliar[k] = array[i];
		i++;
		k++;
	}
	
	while(j <= fim)
	{
		auxiliar[k] = array[j];
		j++;
		k++;
	}
	
	for(k = 0, i = inicio; i <= fim; i++, k++){
		array[i] = auxiliar[k];
	}
}

void mergeSort(int *array, int inicio, int fim) 
{
	int meio = (inicio + fim) / 2;
	
	if(inicio < fim) 
	{
		mergeSort(array, inicio, meio);
		mergeSort(array, meio + 1, fim);
		merge(array, inicio, meio, fim);
	}
}



main () {
	int tam = 6;
	int vetor[tam] = {20,7,2,1,14,0};
	
	mergeSort(vetor,0,tam-1);
	
	printArray(vetor, 0, tam-1);
}

