#include <stdio.h>

int isPrime(int);

int main(){
    int s;
    scanf("%i", &s);
    isPrime(s);
    
    if(isPrime(s) && isPrime((2 * s) + 1))
        printf("Sophie");
    else
        printf("Nope");
    
    return 0;
}

int isPrime (int s){
    int cf = 2, prime = 1;
    
    while(prime == 1 && cf*cf <= s){
        if(s % cf == 0){
            prime = 0;
        }
        cf++;
    }
    
    return prime;
}