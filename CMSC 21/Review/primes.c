#include <stdio.h>

int isPrime(int);
int f(int);

int main(){
    int x, cf;

    scanf("%i",&x);
    isPrime(x);
    return 0;
}

int isPrime(int n){
    int cf=2, prime = 1;
    
    while(prime == 1 && cf*cf <= n){
        if(n % cf == 0)
            prime = 0;
        cf++;//cf = cf + 1;
    }
    return prime;
    }
}

int f(int x){
    int result = 2*x + 1;

    return result;
}