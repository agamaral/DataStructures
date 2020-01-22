#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int pesqB(int *v, int *tam, int *m, int key)
{
    int i;
    //se for igual ao ponto medio, retorna a posicao direto
    if (key == m[i])
    {
        return i;
    }
    if (key > m[i])
    {
        i++;
        return pesqB(v,tam,m,key);
    }
    else
    {
        i--;
        return pesqB(v,tam,m,key);
    }
}
*/
int pesqB(int *v,int chave);

int main()
{
    int i,f,m,chave;
    int v[10] = {0,1,2,3,4,5,6,7,8,9};
    
    printf("Digite sua chave:\n");
    scanf("%d",&chave);

    printf("A posicao eh %d\n", pesqB(v,chave));

    return 0;
}
int pesqB(int *v,int chave)
{
    int i,f,m=10;
    i=0;
    f = m;
    while(f>i){
        m = (i+f)/ 2;
        if ( v[m] == chave){
            return m;
        }
        if (chave <v[m]){
            f = m ;
        }
        else {
            i = m ;
        }
    }
}