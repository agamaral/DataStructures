#include<stdio.h>
#define n 8

typedef struct {
	int itens[n];
	int fim;
} fila;

void iniciaFila (fila *f) {
     f->fim = -1;
}

int filaVazia (fila f) {
    return (f.fim == -1);
}

void insere (fila*f,int valor) {
	if (f->fim >=n){
		printf("Fila cheia");
	}	
	else {
		f->fim=f->fim+1;
		f->itens[f->fim]=valor;
	}          
}

int retira(fila*f)
{
    int valor,i;
    if (filaVazia(*f))
        printf("Fila vazia\n");
    else{
            valor = f->itens[0];
            for(i=0;i<f->fim-1;i++)
            {
               f->itens[i]=f->itens[i+1];
            }
            f->fim=f->fim-1;
            return valor;
        }
}
main(){
	fila f;
	iniciaFila(&f);
	insere(&f, 10);
	int rem = retira(&f);
	printf("%d", rem);
}
