#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TAM 50000
#define OPCAO 0

void bubblesort(int vetor[], int n) ;

int main()
{
	unsigned int i, j = 0;
	struct timeval start, stop;
	double secs = 0;
	srand(time(NULL)); //chama apenas 1 vez*/

	int *vetor = (int *)malloc(TAM * sizeof(int *));
	if (vetor == NULL)
	{
		printf("Nao foi possivel alocar o vetor");
		return 0;
	}

	for (i = 0; i < TAM; i++)
	{
		if (OPCAO) //faz se OPCAO 1
		{
			*(vetor + i) = rand() % TAM; // retorna um valor entre 0 e TAM
		}
		else
		{
			*(vetor + i) = i;
		}
	}

	for (j = TAM - 1; j >= TAM - 10; j--)
	{
		printf("%d ", *(vetor + j));
	}

    printf("\nCarrega funcao...");
    gettimeofday(&start, NULL);
	bubblesort(vetor,TAM);
    gettimeofday(&stop, NULL);
    printf("\nFinaliza funcao...");
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("\nTempo decorrido %f em segundo(s)\n", secs);

    free(vetor);
}

void bubblesort (int vetor[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
