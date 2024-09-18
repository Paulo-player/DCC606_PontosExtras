#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int arr[99999], aux[99999];
    int n, k, i, sum;

    while (scanf("%d %d", &n, &k) != EOF) {
        aux[0] = 0;
        arr[0] = 0;
        
        for (i = 1; i < n; i++) {
            scanf("%d", &aux[i]);
            arr[i] = aux[i] - aux[i - 1];
        }
        
        qsort(arr, n, sizeof(int), compare);

        sum = 0;
        for (i = k - 1; i < n; i++)
            sum += arr[i];

        printf("%d\n", sum);
    }

    return 0;
}