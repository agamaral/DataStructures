#include <stdio.h>

void select(int *v,int t);

int main(){
    int *v,t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&v[i]);
    }
    select(v,t);
    for(i=0;i<t;i++){
        printf("%d",&v[i]);
    }
    printf("\n");
    
    return 0;
}
void select(int *v, int t){
    int j,i,menor,posicao;
    for(j=0;j<t;j++){
        menor = v[j];
        posicao = j;
        for(i=1;i<t;i++){
            if(v[i] < menor){
                menor = v[i];
                posicao = i;
            }
        }
        int aux = v[j];
        v[j]=menor;
        v[posicao] = aux;
    }
}