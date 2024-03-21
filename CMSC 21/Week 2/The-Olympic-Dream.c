#include <stdio.h>

double minimum (double [], int);
double maximum (double [], int);
double average (double [], int);
void judges (double [], int, double);
void remove_then_assign (double [], int, double);

int main() {
    double center[10], remote[10], combined[20], minC, maxC, minR, maxR, minCom, maxCom;
    int cases, i;

    scanf ("%i", &cases);

    while (cases > 0) {
        for (i = 0; i < 10; i++)
            scanf ("%lf", &center[i]);

        for (i = 0; i < 10; i++)
            scanf ("%lf", &remote[i]);

        minC = minimum (center, 10);
        maxC = maximum (center, 10);
        minR = minimum (remote, 10);
        maxR = maximum (remote, 10);

        judges (center, 10, minC);
        judges (center, 10, maxC);
        printf ("\n");
        judges (remote, 10, minR);
        judges (remote, 10, maxR);
        printf("\n");

        remove_then_assign (center, 10, minC); 
        remove_then_assign (center, 10, maxC);
        remove_then_assign (remote, 10, minR);
        remove_then_assign (remote, 10, maxR);

        for (i = 0; i < 10; i++)
            combined[i] = center[i];

        for (i = 0; i < 10; i++)
            combined [i + 10] = remote[i];

        minCom = minimum (combined, 20);
        maxCom = maximum (combined, 20);

        judges (combined, 20, minCom);
        judges (combined, 20, maxCom);

        printf("\n");

        remove_then_assign (combined, 20, minCom);
        remove_then_assign (combined, 20, maxCom);

        printf ("%0.2lf", average (combined, 20));
        printf("\n");

        cases--;
    }

    return 0;
}
double minimum (double A[], int n) {
    int i;
    double min = 10;

    for (i = 0; i < n; i++) {
        if (A[i] < min && A[i] != 0)
            min = A[i];
    }

    return min;
}

double maximum (double A[], int n) {
    int i;
    double max = A[0];

    for (i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }

    return max;
}

double average (double A[], int n) {
    int i, count = 0;
    double sum = 0, ave = 0;

    for (i = 0; i < n; i++) {
        if (A[i] != 0)
            count++;
    }

    for (i = 0; i < n; i++)
        sum += A[i];

    ave = sum/count;

    return ave;
}

void judges (double A[], int n, double val) {
    int i = 0;

    for (i = 0; i < n; i++) {
        if (A[i] == val)
            printf ("%i ", (i % 10) + 1);
    }
}

void remove_then_assign (double A[], int n, double score) {

    for (int i = 0; i < n; i++) {
        if (A[i] == score) {
            A[i] = 0;
            break;
        }
    }
}