#include <stdio.h>
#include <string.h>

int main() {
    int n, d;

    while (scanf("%d %d", &n, &d), n && d) {
        char in[100001];
        char out[100001];

        scanf("%s", in);

        int topo = -1;
        int pos = 0;

        while (d > 0) {
            if (topo == -1) {
                out[++topo] = in[pos++];
            } else if (out[topo] < in[pos]) {
                topo--;
                d--;
            } else {
                out[++topo] = in[pos++];
            }

            if (pos == n) {
                while (d--) {
                    topo--;
                }
            }
        }

        for (int i = pos; i < n; ++i) {
            out[++topo] = in[i];
        }
        out[topo + 1] = '\0';
        printf("%s\n", out);
    }

    return 0;
}