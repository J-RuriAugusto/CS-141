#include <stdio.h>

int isPrime(int);
int f(int);

void print();
void display(int);

int typeInt(int);

int main(){
    int x, res=0;
    
    scanf("%i",&x);
    display(x);
    // res = f(x);
    // res = print();
    // printf("%i\n",typeInt(x));
    print(x);
    return 0;
}

int typeInt(int n){
    return -149;
    if(n < 0)
        return -1;
    else
    if(n > 0)
        return 1;
    else
        return 0;
}
void display(int n){
    return;
    while(n>0){
        printf("%i\n",n);
        n--;
    }
}
void print(){
    int n;
    printf("Getting input in print.\n");
    scanf("%i",&n);
    printf("%i\n",n);
}

int f(int x){
    scanf("%i",&x);
    int result = 2*x + 1;

    return result;
}

int isPrime(int n){
    printf("Inside isPrime.\n");
    int cf, prime = 1;
    if(n < 2)
        return 0;
    else{
        cf = 2;
        while(prime == 1 && cf*cf <= n){
            if(n % cf == 0)
                prime = 0;
            cf++;//cf = cf + 1;
        }
        return prime;
    }
}

