#include <stdio.h>

void printLine ();
void oddValues (int);
long long factorial ();
int digitNumber (int);

int main(){
    int n;
    scanf ("%i", &n);
    
    if (n == 1){
        scanf ("%i", &n);
        
        printLine ();
    }
    else
    if (n == 2){
        scanf ("%i", &n);
        
        oddValues (n);
    }
    else
    if (n == 3){
        printf("%lld", factorial ());
    }
    else
    if (n == 4){
        scanf ("%i", &n);
        
        printf("%i", digitNumber (n));
    }
    
    return 0;
}

void printLine (){
    int i;
    
    for (i = 0; i < 20; i++)
        printf ("This is Function Basics MP\n");
}

void oddValues (int n){
    
    for (n; n >= 1; n--){
        if (n % 2 == 1)
        //n = n - 2;
        
        printf ("%i ", n);
    }
}

long long factorial (){
    int n = 13;
    long long res = 1;
    
    for (n; n >= 1; n--)
        res *= n;
        
    return res;
}

int digitNumber (int n){
    
    n = n * 1001;

    n /= 7;
    n /= 11;
    n /= 13;
    
    return n;
}