#include <stdio.h>
#include <string.h>

int digitConversion (char, int);
char charConversion (int, int);
void strRev (char [], int);
void addition (char[], char[], char[], int);
void subtraction (char[], char[], char[], int);

int main() {
    char s1[100], s2[100], sum[100], diff[100];
    int base, i;

    if (scanf("%s%s%i", s1, s2, &base) != 3) {
        printf("INVALID INPUT");
        return 0;
    }

    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] < '0' || (s1[i] > '9' && (s1[i] < 'A' || s1[i] > 'A' + base - 11))) {
            printf("INVALID INPUT");
            return 0;
        }
    }

    for (i = 0; i < strlen(s2); i++) {
        if (s2[i] < '0' || (s2[i] > '9' && (s2[i] < 'A' || s2[i] > 'A' + base - 11))) {
            printf("INVALID INPUT");
            return 0;
        }
    }

    addition (s1, s2, sum, base);
    subtraction (s1, s2, diff, base);

    printf ("%s %s", sum, diff);

    return 0;
}

char charConversion (int digit, int base) {
    if (digit < 10) {
        return digit + '0';
    } else {
        return digit - 10 + 'A';
    }
}

int digitConversion (char x, int base) {
    if (x >= '0' && x <= '9') {
        return x - '0';
    } else {
        return x - 'A' + 10;
    }
}

void strRev (char str[], int len) {
    int i = 0;

    for (; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void addition (char s1[], char s2[], char res[], int base) {
    int len_s1 = strlen(s1), len_s2 = strlen(s2), carry = 0, digit_sum, sum_size = 0; 

    for (int i = 1; i <= len_s1 || i <= len_s2 || carry > 0; i++) {
        int digit_s1 = i <= len_s1 ? digitConversion (s1[len_s1 - i], base) : 0;
        int digit_s2 = i <= len_s2 ? digitConversion (s2[len_s2 - i], base) : 0;

        digit_sum = digit_s1 + digit_s2 + carry;
        carry = digit_sum >= base;

        res[sum_size++] = charConversion (digit_sum % base, base);
    }

    res[sum_size] = '\0';
    strRev (res, sum_size);
}

void subtraction(char s1[], char s2[], char res[], int base) {
    int len_s1 = strlen(s1), len_s2 = strlen(s2), i;

    strRev (s1, len_s1);
    strRev (s2, len_s2);

    for (i = 0; i < len_s2; i++) {
        int digit_s1 = digitConversion (s1[i], base);
        int digit_s2 = digitConversion (s2[i], base);

        if (digit_s1 < digit_s2) {
            digit_s1 += base;
        }

        int digit_diff = digit_s1 - digit_s2;
        res[i] = charConversion (digit_diff, base);
    }

    for (; i < len_s1; i++) {
        int digit_s1 = digitConversion (s1[i], base);

        if (digit_s1 < 0) {
            digit_s1 += base;
        }
        res[i] = charConversion (digit_s1, base);
    }

    while (res[i - 1] == '0' && i > 1) {
        i--;
    }

    res[i] = '\0';
    strRev (res, i);
}
