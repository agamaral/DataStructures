#include <stdio.h>
#include <stdlib.h>

int contavezes(int v[7], int key,int i, int conta);

int main(){
    int conta=0;
    int v[7] = {1,2,3,4,5,2,2};
    printf("Chave encontrada %d vezes\n",contavezes(v,2,7,conta));
    return 0;
}

int contavezes(int v[7], int key,int i, int conta){
   if ( i < 0 ){
       return conta;
   }
   if ( v[i] == key ){
       conta++;
       return contavezes(v,key,--i,conta);
   }
   else{
       return contavezes(v,key,--i,conta);
   }
}
