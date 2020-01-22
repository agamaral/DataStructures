#include <stdio.h>
#include <stdlib.h>

struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;

};

void criarFila( struct Fila *f, int c ) {

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover( struct Fila *f ) {

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

void main () {

	int opcao, capa;
	float valor;
	struct Fila umaFila;

	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);

	inserir(&umaFila, 5);
	inserir(&umaFila, 10);
	mostrarFila(&umaFila);
	remover(&umaFila);
	mostrarFila(&umaFila);

	return 0;
}

