#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochilaBinaria(int pizzas, int pizzap[], int tempo[], int n) {
  
    if (n == 0 || pizzas == 0)
        return 0;
    if (pizzap[n-1] > pizzas)
        return mochilaBinaria(pizzas, pizzap, tempo, n-1);
    else
        return max(tempo[n-1] + mochilaBinaria(pizzas - pizzap[n-1], pizzap, tempo, n-1), mochilaBinaria(pizzas, pizzap, tempo, n-1));
}

int main() {
    int n, pizzas, min, i;

    while (true) {
        scanf("%d", &n);

        if (n == 0)
            break;
        
        scanf("%d", &pizzas);

        int tempoTotal[n], qtPizzas[n];
        for (i = 0; i < n; i++)
            scanf("%d %d", &tempoTotal[i], &qtPizzas[i]);

        min = mochilaBinaria(pizzas, qtPizzas, tempoTotal, n);

        printf("%d min.\n", min);
    }

    return 0;
}