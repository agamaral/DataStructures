#include <stdio.h>
#include <stdlib.h>

int pesquisaRec(int *v, int key,int i);

int main(){
    int v[] = {1,2,3,4,5};
    printf("Chave encontrada em %d\n",pesquisaRec(v,2,5));
    return 0;
}

int pesquisaRec(int *v, int key,int i){
   if ( i < 0 ){
       return -1;
   }
   if ( v[i] == key ){
       return 1;
   }
   return pesquisaRec(v,key,--i);
}
