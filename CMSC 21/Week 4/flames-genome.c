#include <stdio.h>

int flames (char [], char []);
void genome (char [], char []);

int main () {
    int cases, option, s1, s2, sum = 0;
    char str1[500], str2[500];

    scanf ("%i", &cases);

    while (cases--) {
        scanf ("%i", &option);

        switch (option) {

            case 1:
                scanf (" %[^\n]", str1);
                scanf (" %[^\n]", str2);
                
                s1 = flames (str1, str2);
                s2 = flames (str2, str1);

                sum = (s1 + s2) % 6;
                
                switch (sum) {
                    case -2:
                        printf ("They are not a thing. They will never be.\n");
                        break;
                    case 1:
                        printf ("They will end up as FRIENDS.\n");
                        break;
                    case 2:
                        printf ("They will end up as LOVERS.\n");
                        break;
                    case 3:
                        printf ("They will ACCEPT their fate, whatever it is.\n");
                        break;
                    case 4:
                        printf ("They will end up as a MARRIED couple.\n");
                        break;
                    case 5:
                        printf ("They will be ENGAGED.\n");
                        break;
                    case 0:
                        printf ("They will end up as SWEETHEARTS.\n");
                        break;
                }

                break;

            case 2:
                scanf ("%s%s", str1, str2);
                
                genome (str1, str2);
                break;
        }
    }
}

int flames (char s1[], char s2[]) {
    int i = 0, j, count = 0, res = 0;

    for (; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if ((s1[i] == s2[j] && s1[i] != ' ') || ((s1[i] + 32) == s2[j] && s1[i] != ' ') || (s1[i] - 32 == s2[j] && s2[j] != ' ')) {
                count++;
                break;
            }
        }
    }

    if (count == 0) {
        count--;
    }

    res = count % 6;

    switch (res) {
        case -1:
            printf ("%s does not want to have anything to do with %s.\n", s1, s2);
            break;
        case 1:
            printf ("%s wants to be FRIENDS with %s.\n", s1, s2);
            break;
        case 2:
            printf ("%s wants to be LOVERS with %s.\n", s1, s2);
            break;
        case 3:
            printf ("%s wants to ACCEPT their fate with %s.\n", s1, s2);
            break;
        case 4:
            printf ("%s wants to be MARRIED to %s.\n", s1, s2);
            break;
        case 5:
            printf ("%s wants to be ENGAGED to %s.\n", s1, s2);
            break;
        case 0:
            printf ("%s wants to be SWEETHEARTS with %s.\n", s1, s2);
            break;
    }

    return count;
}

void genome (char s1[], char s2[]) {
    int s1_len = 0, s2_len = 0, i = 0, k = 0, j, l = 0,  count = 0, frequency = 0, index[100];

    for (; s1[s1_len] != '\0'; s1_len++);
    for (; s2[s2_len] != '\0'; s2_len++);
    
    for (; i != s1_len; i++) {
        if (s2[0] == s1[i]) {
            k = i;
            for (j = 0; j != s2_len; j++) {
                if (s2[j] == s1[k++]) {
                    count += 1;
                }
            }
            if (count == s2_len) {
                index[frequency] = i;
                frequency++;
            }
            count = 0;
        }
    }
    if (frequency > 0) {
        printf ("YES\n%i\n", frequency);
        for (; l != frequency; l++) {
            printf ("%i ", index[l]);
        }
    }
    else
        printf ("NO\n");
}