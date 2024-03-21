#include <stdio.h>

void reverse (int [], int);
void palindrome (int [], int);
void search (int [], int);
void countFrequency (int [], int);

int main() {
    int cases, item, inputs[20], i;

    scanf ("%i", &cases);
 
    while (cases) {
        scanf ("%i", &item);

        switch (item) {
            case 1: for (i = 0; i < 10; i++) {
                        scanf("%i", &inputs[i]);
                    }  
                    
                    reverse (inputs, 10);
                    break;

            case 2: for (i = 0; i < 10; i++)
                        scanf ("%i", &inputs[i]);

                    palindrome (inputs, 10);
                    break;

            case 3: for (i = 0; i < 11; i++)
                        scanf ("%i", &inputs[i]);

                    search (inputs, 11);
                    break;

            case 4: for (i = 0; i < 20; i++)
                        scanf("%i", &inputs[i]);

                    countFrequency (inputs, 20);
                    break;
            
            default: printf ("\nYour input is not an integer.");
        };
        cases--;
    }

    return 0;
}

void reverse (int input[], int n) {
    int i = 0,  arr[n];
    
    for (i; i < n; i++)
        arr[n - 1 - i] = input[i];

    for (i = 0; i < n; i++){
        input[i] = arr[i];
        printf("%i ", input[i]);
    }
    printf ("\n");
}

void palindrome (int input[], int n) {
    int i, j = 0, palindrome = 1;
    for (i = 0, j = (n - 1); i < j; i++, j--) {
        if (input[i] != input[j]) {
            palindrome = 0;
            break;
        }
    }
    
    if (palindrome == 0)
    printf ("No\n");
    else
    printf ("Yes\n");
}

void search (int input[], int n) {
    int isFound = 0;

    for (int i = 0; i < n - 1; i++) {
        if (input[i] == input[10]) {
            isFound = 1;
            break;
        }
    }

    if (isFound == 1)
        printf ("Yes\n");
    else
        printf ("No\n");
}

void countFrequency (int input[], int n) {
    int i, num, counts[20] = {0}, digitCount;

    for (i = 0; i < n; i++){

        num = input[i];
        digitCount = 0;
        
        if (num == 0)
            digitCount = 1;
        else {
            do {
                num /= 10;
                digitCount++;
            } while (num != 0);
        }
            counts[digitCount]++;
    }      

    for (int i = 1; i <= 10; i++) 
        printf("%d - %d\n", i, counts[i]);
}


// #include <stdio.h>

// void reverse_array(int arr[], int n) {
//     for (int i = n-1; i >= 0; i--) {
//         printf("%d ", arr[i]);
//     }
// }

// void check_palindrome(int arr[], int n) {
//     for (int i = 0; i < n/2; i++) {
//         if (arr[i] != arr[n-1-i]) {
//             printf("No\n");
//             return;
//         }
//     }
//     printf("Yes\n");
// }

// void search_int(int arr[], int n, int target) {
//     int found = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == target) {
//             found = 1;
//             break;
//         }
//     }
//     if (found) {
//         printf("Yes\n");
//     } else {
//         printf("No\n");
//     }
// }

// void count_digits(int arr[], int n) {
//     int count[11] = {0}; // index 0 is unused, count[i] stores the number of i-digit numbers
//     for (int i = 0; i < n; i++) {
//         int digits = 0;
//         int num = arr[i];
//         while (num > 0) {
//             digits++;
//             num /= 10;
//         }
//         count[digits]++;
//     }
//     for (int i = 1; i <= 10; i++) {
//         printf("%d - %d\n", i, count[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int num_tests;
//     scanf("%d", &num_tests);
//     for (int i = 0; i < num_tests; i++) {
//         int menu;
//         scanf("%d", &menu);
//         if (menu == 1) {
//             int arr[10];
//             for (int j = 0; j < 10; j++) {
//                 scanf("%d", &arr[j]);
//             }
//             reverse_array(arr, 10);
//             printf("\n");
//         } else if (menu == 2) {
//             int arr[10];
//             for (int j = 0; j < 10; j++) {
//                 scanf("%d", &arr[j]);
//             }
//             check_palindrome(arr, 10);
//         } else if (menu == 3) {
//             int arr[11];
//             for (int j = 0; j < 11; j++) {
//                 scanf("%d", &arr[j]);
//             }
//             search_int(arr, 10, arr[10]);
//         } else if (menu == 4) {
//             int arr[20];
//             for (int j = 0; j < 20; j++) {
//                 scanf("%d", &arr[j]);
//             }
//             count_digits(arr, 20);
//         }
//     }
//     return 0;
// }