#include <stdio.h>

int computeLog (int);
int computeFloor (double);
int computeCeiling (double);
int alphanumeric (char);
int letter (char);
int uppercaseLetter (char);
int lowercaseLetter (char);
char uppercaseEquivalent (char);
char lowercaseEquivalent (char);
char punctuationMark (char);
int integerEquivalent (char []);
double doubleEquivalent (char []);
float correctFloat (char []);
int absoluteValue (int);
void copyContents (char [], char []);
int substring (char [], char []);
int same_or_not (char [], char []);
void camelCase (char []);
void stringReverse (char []);
int integerReverse (int);


int main()
{
    int cases, item, inputs;
    double double_inputs;
    char character_inputs, first_string_inputs[50], second_string_inputs[50];

    scanf ("%i", &cases);

    while (cases--)
    {
        scanf ("%i", &item);

        switch (item)
        {
            case 1: 
                    scanf ("%i", &inputs);

                    printf ("%i\n", computeLog (inputs));
                    break;

            case 2:
                    scanf ("%lf", &double_inputs);

                    printf ("%d\n", computeFloor (double_inputs));
                    break;

            case 3:
                    scanf ("%lf", &double_inputs);

                    printf ("%d\n", computeCeiling (double_inputs));
                    break;

            case 4:
                    scanf (" %c", &character_inputs);
                    
                    if (alphanumeric (character_inputs))
                        printf("YES\n");
                    else
                        printf ("NO\n");
                    break;
                
            case 5:
                    scanf (" %c", &character_inputs);
                    
                    if (letter (character_inputs)) {
                        printf("YES\n");
                    }
                    else
                        printf ("NO\n");
                    break;
            
            case 6:
                    scanf (" %c", &character_inputs);
                    
                    if (uppercaseLetter (character_inputs)) {
                        printf("YES\n");
                    }
                    else
                        printf ("NO\n");
                    break;
            
            case 7:
                    scanf (" %c", &character_inputs);
                    
                    if (lowercaseLetter (character_inputs)) {
                        printf("YES\n");
                    }
                    else
                        printf ("NO\n");
                    break;
            
            case 8: 
                    scanf (" %c", &character_inputs);

                    printf ("%c\n", uppercaseEquivalent (character_inputs));
                    break;

            case 9: 
                    scanf (" %c", &character_inputs);

                    printf ("%c\n", lowercaseEquivalent (character_inputs));
                    break;

            case 10: 
                    scanf (" %c", &character_inputs);
                    
                    if (punctuationMark (character_inputs)) {
                        printf("YES\n");
                    }
                    else
                        printf ("NO\n");
                    break;

            case 11: 
                    scanf ("%s", first_string_inputs);
                    
                    printf("%i\n", integerEquivalent (first_string_inputs));
                    break;
            
            case 12: 
                    scanf ("%s", first_string_inputs);
                    
                    printf("%0.4f\n", doubleEquivalent (first_string_inputs));
                    break;

            case 13: 
                    scanf ("%s", first_string_inputs);
                    
                    if (correctFloat (first_string_inputs)) {
                        printf("YES\n");
                    }
                    else
                        printf ("NO\n");
                    break;
            
            case 14: 
                    scanf ("%i", &inputs);

                    printf("%i\n", absoluteValue (inputs));
                    break;

            case 15: 
                    scanf ("%s", first_string_inputs);
                    scanf ("%s", second_string_inputs);

                    copyContents (first_string_inputs, second_string_inputs);
                    
                    printf("%s\n", second_string_inputs);
                    break;
            
            case 16: 
                    scanf ("%s", first_string_inputs);
                    scanf ("%s", second_string_inputs);

                    if (substring (first_string_inputs, second_string_inputs) == 1) {
                        printf("YES\n");
                    }
                    else
                        printf ("NO\n");
                    break;

            case 17: 
                    scanf ("%s", first_string_inputs);
                    scanf ("%s", second_string_inputs);

                    if (same_or_not (first_string_inputs, second_string_inputs) == 0)
                        printf("YES\n");
                    else if (same_or_not (first_string_inputs, second_string_inputs) < 0) {
                        printf ("BEFORE\n");}
                    else 
                        printf ("AFTER\n");
                    break;                                                                            

            case 18: 
                    scanf("%[^\n]", first_string_inputs);
                    
                    camelCase (first_string_inputs);

                    printf("%s\n", first_string_inputs);
                    break;
            
            case 19:        
                    scanf("%s", first_string_inputs);
                    
                    stringReverse (first_string_inputs);

                    printf("%s\n", first_string_inputs);
                    break;

            case 20: 
                    scanf ("%i", &inputs);

                    printf("%i\n", integerReverse (inputs));
                    break;
            
        }
    }
}

/*1*/int computeLog (int inputs) {
    int count = 0;

    while (inputs >= 10) {
        inputs /= 10;
        count++;
    }

    return count;
}

/*2*/int computeFloor (double inputs) {
    int result = (int)inputs;

    if (inputs < 0 && inputs != (double)result) {
        result--;
    }

    return result;
}

/*3*/int computeCeiling (double inputs) {
    int result = (int)inputs;

    if (inputs > result){
        return result + 1;
    } 
    else 
        return result;
}

/*4*/int alphanumeric (char inputs) {
    if ((inputs >= '0' && inputs <= '9') || (inputs >= 'a' && inputs <= 'z') || (inputs >='A' && inputs <= 'Z')) {
        return 1;
    }
    else
        return 0;
}

/*5*/int letter (char inputs) {
    if ((inputs >= 'a' && inputs <= 'z') || (inputs >='A' && inputs <= 'Z')) {
        return 1;
    }
    else
        return 0;
}

/*6*/int uppercaseLetter (char inputs) {
    if (inputs >='A' && inputs <= 'Z') {
        return 1;
    }
    else
        return 0;
}

/*7*/int lowercaseLetter (char inputs) {
    if (inputs >= 'a' && inputs <= 'z') {
        return 1;
    }
    else
        return 0;
}

/*8*/char uppercaseEquivalent (char inputs) {
    if ((inputs >= 'A' && inputs <= 'Z') || (inputs >= '0' && inputs <= '9') || (inputs == '.') || (inputs == '?') || (inputs == '!') || (inputs == ',') || (inputs == ';') || (inputs == ':') || (inputs == '*')) {
        return inputs;
    }
    else
        return inputs - 'a' + 'A';
}

/*9*/char lowercaseEquivalent (char inputs) {
    if ((inputs >= 'a' && inputs <= 'z') || (inputs >= '0' && inputs <= '9') || (inputs == '.') || (inputs == '?') || (inputs == '!') || (inputs == ',') || (inputs == ';') || (inputs == ':') || (inputs == '*')) {
        return inputs;
    }
    else
        return inputs - 'A' + 'a';
}

/*10*/char punctuationMark (char inputs) {
    if ((inputs == '.') || (inputs == '?') || (inputs == '!') || (inputs == ',') || (inputs == ';') || (inputs == ':')) {
        return 1;
    }
    else
        return 0;
}

/*11*/int integerEquivalent (char inputs[]) {
    int result = 0, sign = 1, i = 0;

    if (inputs[0] == '-')
    {
        sign = -1;
        i++;
    }
    
    for ( ; inputs[i] != '\0'; i++)
    {
        result = result*10 + (inputs[i] - '0');
    }
    return result * sign;
}

/*12*/double doubleEquivalent (char inputs[]) {
    int i = 0, sign = 1;
    double result = 0.0, decimal = 0.1;

    if (inputs[0] == '-')
    {
        sign = -1;
        i++;
    }
    
    for ( ; inputs[i] != '\0'; i++)
    {
        if (inputs[i] == '.')
        {
            i++;

            for ( ; inputs[i] != '\0'; i++)
            {
                result += (inputs[i] - '0') * decimal;
                decimal /= 10.0;
            }
            break;
        }
        result = result * 10.0 + (inputs[i] - '0');
    }

    return result * sign;
}

/*13*/float correctFloat (char inputs[]) {
    int i = 0, j = 0, dot = 0, alphabet = 0;

    for ( ; inputs[i] != '\0'; i++)

    for ( ; j < i; j++)
    {
        if (inputs[j] == '.')
            dot++;
        else if (((inputs[j] >= 'A') && (inputs[j] <= 'Z')) || ((inputs[j] >= 'a') && (inputs[j] <= 'z')))
            alphabet++;
    }

    if (dot > 1 || alphabet > 0)
        return 0;
    else
        return 1;
}

/*14*/int absoluteValue (int inputs) {
    if (inputs > 0)
        return inputs;
    else
        return -inputs; 
}

/*15*/void copyContents (char source_inputs[], char destination_inputs[]) {
    int i = 0;

    for ( ; source_inputs[i] != '\0'; i++) {
        destination_inputs[i] = source_inputs[i];}

    destination_inputs[i] = '\0';
}

/*16*/int substring (char first_string[], char second_string[]) {
    int i, j, length_one = 0, length_two = 0;

    for ( ; first_string[length_one] != '\0'; length_one++);

    for ( ; second_string[length_two] != '\0'; length_two++);

    for (i = 0; i <= length_two - length_one; i++)
    {
        for (j = 0; j < length_one; j++) {
            if (first_string[j] != second_string[i + j])
                break;}

        if (j == length_one)
            return 1;
    }

    return 0;
}

/*17*/int same_or_not (char first_string[], char second_string[]) {
    int i = 0;

    for ( ; first_string[i] == second_string[i]; i++) {
        if ((first_string[i] == '\0') || (second_string[i] == '\0'))
            break;
    }
    
    if (first_string[i] == '\0' && second_string[i] == '\0')
        return 0;
    else if (first_string[i] < second_string[i])
        return -1;
    else if (first_string[i] > second_string[i])
        return 1;
    else
        return -2;
}

/*18*/void camelCase (char inputs[]) {
    int i;
    
    for (i = 0; inputs[i] != '\0'; i++) { 
        if((inputs[i] >= 'A') && (inputs[i] <= 'Z')) {
            inputs[i] = inputs[i] + 'a' - 'A';}
    }

    for(i = 1; inputs[i] != '\0'; i += 2) {
        if (inputs[i] == ' ') {
            continue;}

        inputs[i] = inputs[i] - ('a' - 'A');
    }
}

/*19*/void stringReverse (char strings[]) {
    int i, length = 0;
    char temp;

    while (strings[length] != '\0') {
        length++;
    }

    for (i = 0; i < length / 2; i++) {
        temp = strings[i];
        strings[i] = strings[length - i - 1];
        strings[length - i - 1] = temp;
    }
}

/*20*/int integerReverse (int inputs) {
    int reverse = 0;

    do
    {
        reverse = reverse * 10 + inputs % 10;
        inputs /= 10;
    } while (inputs != 0);

    return reverse;
}