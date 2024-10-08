#include <stdio.h>
#include <math.h>

int array[51];
int total, N;

void calcula(int v, int p) {
    if (p == N) return;

    if (array[p] == 0) {
        array[p] = v;
        total++;
        calcula(v + 1, p);
        return;
    }

    for (int i = 0; i <= p; i++) {
        int raiz = (int)sqrt(array[i] + v);
        if (pow(raiz, 2) == array[i] + v) {
            array[i] = v;
            total++;
            calcula(v + 1, p);
            return;
        }
    }
    calcula(v, p + 1);
}

int main() {
    int testes;
    scanf("%d", &testes);

    for (int i = 0; i < testes; i++) {
        scanf("%d", &N);

        for (int i = 0; i < 50; i++)
            array[i] = 0;

        total = 0;
        calcula(1, 0);
        printf("%d\n", total);
    }

    return 0;
}
