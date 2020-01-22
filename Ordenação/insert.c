#include <stdio.h>
#include <stdlib.h>

void insert(int *v, int conta);

main(){
    int i,j,eleito,conta =6;
    int v[6] = {3,2,7,5,0,9};

    printf("Vetor normal = \n");
    for(i=0;i<conta;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    insert(v,conta);
    printf("Vetor ordenado = \n");
    for(i=0;i<conta;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}

void insert(int *v, int conta){
    int i,j,eleito;

    for(i=1;i<conta-1;i++){
        eleito = v[i];
        j = i -1;

        while( j>=0 && v[j] > eleito ){
            v[j+1] = v[j];
            j = j -1;
        }
        v[j+1] = eleito;
    }
}