void timesTable (int arr[], int n) {
    int i, j, k;
    for (i = 0; i < n; i++){
        for (k = 1; k <= 10; k++) {
            for (j = 0; j < arr[i]; j++) {
                printf ("%2i * %2i = %2i    ", j + 1, k, ((j + 1) * k));
            }
            printf ("\n");
        }
        printf("\n");
    }
}