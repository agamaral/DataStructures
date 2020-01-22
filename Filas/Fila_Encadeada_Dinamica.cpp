#include<stdio.h>
#include<stdlib.h>

typedef struct cel {
    int info;
    struct cel * prox;
};
        
typedef struct fila {
    cel *inicio;
    cel *fim;
    int tamanho;
};

void inicia ( fila * f ){
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void insere ( fila * f , int valor ){
	cel *novo;
	if ((novo = (cel*) malloc(sizeof(cel)))==NULL)
		printf ("Impossivel alocar a memoria\n");
	else {
		novo->info = valor;
		novo->prox = NULL;
		if (f->inicio == NULL) {
			f->inicio = novo;
			f->fim = novo;
		}
		else {
			(f->fim)-> prox = novo;
			f->fim = novo;
		}
		f->tamanho++;
	}							
}

int retira ( fila * f ) {
    if (f->inicio == NULL){
     	printf("Fila Vazia!!!\n");
     	return -1;
	}
    cel *aux = f->inicio;
    int rem = aux->info;
    f->inicio = (f->inicio)->prox;
    free(aux);
    f->tamanho--;
    return rem; 
}

void apresentaFila(fila *f)
{
     cel *aux;
     if (f->inicio == NULL){
     	printf("Fila Vazia!!!\n");
     	return;
	 }
     aux = f->inicio;
     int i = 1;
     while(1)
     {
         printf ("Elemento[%d] = %3d\n",i,(aux->info));
         if (aux->prox == NULL) {
         	break;
         }
         else {
         	aux = aux->prox;
        	i=i+1;
		 }
     }   
}
main(){
    fila f;
    inicia(&f);
    insere(&f,10);
    insere(&f,7);
    insere(&f,8);
    insere(&f,1);
    
    getchar();
    apresentaFila(&f);
    printf("retira = %d\n",retira(&f));
    getchar();
    printf("retira = %d\n",retira(&f));
    getchar();
    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();
}
