#include <stdio.h>
#include <stdbool.h>

int main() {
    int b, n, i, d, c, v;
    bool negativo;

    while (1) {
        scanf("%d %d", &b, &n);

        if (!b && !n)
            break;

        negativo = false;

        // Vetor para armazenar as reservas monetárias
        int reservas[b + 1];
        for (i = 1; i <= b; i++)
            scanf("%d", &reservas[i]);

        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &d, &c, &v);
            // Retira o valor v do banco D
            reservas[d] -= v;
            // E deposita no banco C
            reservas[c] += v;
        }

        // Verifica se há algum banco negativado
        for (i = 1; i <= b; i++) {
            if (reservas[i] < 0) {
                negativo = true;
                break;
            }
        }

        if (negativo)
            printf("N\n");
        else
            printf("S\n");
    }

    return 0;
}