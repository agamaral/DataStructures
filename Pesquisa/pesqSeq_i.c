#include <stdio.h>
#include <stdlib.h>

int pesquisaSequencial(int *v, int key,int tam);

int main(){
    int v[] = {1,2,3,4,5};
    printf("Chave encontrada em %d\n",pesquisaSequencial(v,2,5));
    return 0;
}

int pesquisaSequencial(int *v, int key,int tam){
    int i;

    for(i=0;i<tam;i++){
        if ( v[i] == key){
            return i;
        }
    }
    return -1;// nenhuma key encontrada =(
}