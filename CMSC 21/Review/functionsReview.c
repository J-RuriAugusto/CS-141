#include <stdio.h>

int giveLog(int x){
    int count = 0;

    while (x >= 10)
    {
        x = x/10;
        count++;
    }

    return count;
}

int giveFloor(double x){
    int y = (int)x; 
    if (x < 0 && x != (double)y)
    {
        y--;
    }
    return y;
}

int giveCeiling(double x){
    int y = (int)x; 
    if (x > y)
    {
        return y + 1;
    }
    else
        return y;
}

int isAlphanumeric(char c){
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else 
        return 0;
}

int fromEngAlphabet(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else 
        return 0;
}

int isUppercase(char c){
    if ((c >= 'A' && c <= 'Z'))
        return 1;
    else 
        return 0;
}

int isLowercase(char c){
    if ((c >= 'a' && c <= 'z'))
        return 1;
    else 
        return 0;
}

char giveUppercase(char c){
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 'A';
    }
    else
        return c;
}

char giveLowercase(char c){
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    else
        return c;
}

int isPunctuationmark(char c){
    if (c == '.' || c == '?' || c == '!' || c == ',' || c == ';' || c == ':')
        return 1;
    else
        return 0;
}

int stringToInt(char str[]){
    int num = 0, sign = 1, i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    
    while (str[i] != '\0')
    {
        num = num*10 + (str[i]-'0');
        i++;
    }
    return num*sign;
}

double stringToDouble(char str[]){
    int i = 0, sign = 1;
    double num = 0.0, frac = 0.1;

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    
    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            i++;
            while (str[i] != '\0')
            {
                num += (str[i] - '0') * frac;
                frac /= 10.0;
                i++;
            }
            break;
        }
        
        num = num*10.0 + (str[i]-'0');
        i++;
    }
    return num*sign;
}

int isFloatFormat(char str[]){
    int len = 0, i, point = 0, letter = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    
    for (i = 0; i < len; i++)
    {
        if ((str[i] == '.'))
        {
            point++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letter++;
        }
        
    }

    if (point > 1 || letter > 0)
    {
        return 0;
    }
    else
        return 1;
}

int giveAbsoluteVal(int x){

    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

void copyString(char source[], char destination[]){
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int isSubstring(char str1[], char str2[]){
    int i, j, same = 0, len1 = 0, len2 = 0;

    while (str1[len1] != '\0')
    {
        len1++;
    }
    
    while (str2[len2] != '\0')
    {
        len2++;
    }

    for (i = 0; i <= len2 - len1; i++) 
    {
        for (j = 0; j < len1; j++) 
        {
            if (str1[j] != str2[i + j]) 
            {
                break;
            }
        }
        if (j == len1) 
        {
            return 1;
        }
    }

    return 0;
}

int sameOrNot(char s1[], char s2[]){
    int i = 0;

    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else if (s1[i] < s2[i])
        return -1;
    else if (s1[i] > s2[i])
        return 1;
    else
        return -2;
}

void camelCase(char str[]){
    int i;

    for (i = 0; str[i]!='\0'; i++)
    {
        if (i % 2 == 0)
        {
            if(str[i]>='A' && str[i]<='Z')
                str[i] = str[i] + 'a' - 'A';
        }
        else if(i % 2 == 1)
        {
            if(str[i]>='a' && str[i]<='z')
                str[i] = str[i] + 'A' - 'a';
        }
        else if(str[i] = ' ')
        {
            i--;
        }
    }
}

void reverseString(char str[]){
    int i, len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    
}

int reverse(int num){
    int rev = 0;

    while (num != 0)
    {
        rev = rev*10 + num%10;
        num /= 10;
    }
    return rev; 
}

/* MAIN FUNCTION */

int main(){
    int cases, item, x, log, num;
    char c;

    scanf("%i", &cases);

    while (cases)
    {
        scanf("%i", &item);

        if (item == 1)
        {
            scanf("%i", &x);
            log = giveLog(x);
            printf("%i\n", log);
        }

        else if (item == 2)
        {
            double x;
            int floor;

            scanf("%lf", &x);
            floor = giveFloor(x);
            printf("%d\n", floor);
        }

        else if (item == 3)
        {
            double x;
            int ceiling;

            scanf("%lf", &x);
            ceiling = giveCeiling(x);
            printf("%d\n", ceiling);
        }
        
        else if (item == 4)
        {
            scanf(" %c", &c);

            if (isAlphanumeric(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

        else if (item == 5)
        {
            scanf(" %c", &c);

            if (fromEngAlphabet(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

        else if (item == 6)
        {
            scanf(" %c", &c);

            if (isUppercase(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        
        else if (item == 7)
        {
            scanf(" %c", &c);

            if (isLowercase(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

        else if (item == 8)
        {
            char uppercase;

            scanf(" %c", &c);

            uppercase = giveUppercase(c);
            printf("%c\n", uppercase);
        }

        else if (item == 9)
        {
            char lowercase;

            scanf(" %c", &c);

            lowercase = giveLowercase(c);
            printf("%c\n", lowercase);
        }

        else if (item == 10)
        {
            scanf(" %c", &c);

            if (isPunctuationmark(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

        else if (item == 11)
        {
            char str[100];
            int num;

            scanf("%s", str);

            num = stringToInt(str);
            printf("%i\n", num);
        }
        
        else if (item == 12)
        {
            char str[100];
            double num;

            scanf("%s", str);

            num = stringToDouble(str);
            printf("%.4f\n", num);
        }

        else if (item == 13)
        {
            char str[100];

            scanf("%s", str);

            if (isFloatFormat(str) == 1)
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
        }

        else if (item == 14)
        {
            int x, abs;

            scanf("%d", &x);

            abs = giveAbsoluteVal(x);

            printf("%d\n", abs);
        }

        else if (item == 15)
        {
            char source[100], destination[100];

            scanf("%s", source);
            scanf("%s", destination);

            copyString(source, destination);

            printf("%s\n", destination);
        }
        

        else if (item == 16)
        {
            char str1[100], str2[100];

            scanf("%s", str1);
            scanf("%s", str2);

            if (isSubstring(str1, str2) == 1)
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
            
        }

        else if (item == 17)
        {
            char s1[100], s2[100];

            scanf("%s", s1);
            scanf("%s", s2);

            
            
            if (sameOrNot(s1, s2) == 0)
            {
                printf("YES\n");
            }
            else if (sameOrNot(s1, s2) < 0)
            {
                printf("BEFORE\n");
            }
            else
                printf("AFTER\n");
        }
        
        
        else if (item == 18)
        {
            char str[100];

            scanf(" %[^\n]s", str);

            camelCase(str);

            printf("%s\n", str);
        }

        else if (item == 19)
        {
            char str[100];

            scanf("%s", str);

            reverseString(str);

            printf("%s\n", str);
        }

        else if (item == 20)
        {
            int rev;

            scanf("%i", &num);

            rev = reverse(num);
            printf("%i\n", rev);
        }
        
        cases--;
    }
}

