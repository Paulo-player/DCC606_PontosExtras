#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000 // Valor máximo para o maior elemento no vetor

void count_sort(int *vetor, int n, int maior) {
    int m = maior + 1;
    int *count = (int *)calloc(m, sizeof(int)); // Aloca e inicializa com zero

    if (count == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    // Contar a ocorrência de cada valor
    for (int i = 0; i < n; i++) {
        count[vetor[i]]++;
    }

    // Reconstituir o vetor ordenado
    int j = 0;
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < count[i]; k++) {
            vetor[j++] = i;
        }
    }

    free(count); // Libera a memória alocada
}

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {
        int n;
        scanf("%d", &n);

        int *vetor = (int *)malloc(n * sizeof(int));
        if (vetor == NULL) {
            fprintf(stderr, "Erro de alocação de memória.\n");
            exit(EXIT_FAILURE);
        }

        int maior = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
        }

        count_sort(vetor, n, maior);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", vetor[i]);
        }
        printf("\n");

        free(vetor); // Libera a memória alocada
    }

    return 0;
}