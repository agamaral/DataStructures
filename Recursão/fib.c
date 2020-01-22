#include <stdio.h>
#include <stdlib.h>

int conta=0;

int fibonacci(int N);

int main(){
    int N,fib;

    scanf("%d",&N);

    fib = fibonacci(N);
    
    printf("fib(%d) = %d calls = %d\n",N,fib,conta);

}

int fibonacci(int N){
     if (N == 1){
        return 1;
    }
    else if (N == 0){
        return 0;
    }
    else{
        conta = conta + 2;
        return fibonacci(N-1) + fibonacci(N-2);
    }
}