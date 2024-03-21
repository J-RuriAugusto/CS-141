int isSorted (int arr[], int num) {
    int i, isEqual = 1;
    
    for (i = 1; i < num; i++) {
        if (arr [i] < arr[i - 1])
            return -i;
        else if (arr [i] != arr[i - 1])
            isEqual = 0;
    }
   
   return (isEqual) ? -(i - 1) : i - 1;
}

//     if (isEqual) {
//         return -(i - 1);
//     }
//     return i - 1;
// }