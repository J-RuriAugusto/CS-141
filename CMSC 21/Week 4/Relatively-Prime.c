// I, Jamaica Ruri C. Augusto, pledge upon my honor that I did this MP8 by myself.

#include <stdio.h>

int linear (int, int);
int sublinear (int, int);

int main () {
    int a, b, res;
    
    scanf ("%i%i", &a, &b);
    
    res = linear (a, b);
    
    if (res > 0)
        printf ("Yes %i\n", res);
    else
        printf ("No %i\n", -(res));
        
    res = sublinear (a, b);
    
    if (res > 0)
        printf ("Yes %i\n", res);
    else
        printf ("No %i\n", -(res));

    return 0;
}

int linear (int a, int b) {
    int cf,  count = 0;
    
    cf = a < b ? a : b;
    
    for (; cf > 1; cf--) {
        count++;
        if (a % cf == 0 && b % cf == 0)
            break;
    }
    return (cf == 1) ? count : -count;
}

int sublinear (int a, int b) {
    int r, count = 0;
    
    if (a < b) {
        a = b + a;
        b = a - b;
        a = a - b;
    }
    
    do {
        count++;
        r = a % b;
        a = b;
        b = r;
    } while (r > 0);
    
    return (a == 1) ? count : -count;
}