#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y);

int main(){
    int resultado,x,y;
    scanf("%d%d",&x,&y);

    resultado = mdc(x,y);

    printf("%d\n",resultado);
}


int mdc(int x, int y){

    if (x >= y && x % y == 0){
        return y;
    }
    else if ( x < y ){
        return mdc(y, x);
    }
    else {
        return mdc(y, x % y);
    }
}