#include <stdio.h>

int count (char [], char []);

int main () {
    char s1[100], s2[100];
    int res, resu;
    
    scanf ("%s", s1);
    scanf ("%s", s2);
    
    res = count (s1, s2);
    resu = count (s2, s1);

    printf ("%i\n%i\n", res, resu);
    return 0;
}

int count (char s1[], char s2[]) {
    int i, j, count = 0;
    
    for (i = 0; i < s1[i]; i++) {
        for (j = 0; j < s2[j]; j++) {
            if (s1[i] == s2[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}