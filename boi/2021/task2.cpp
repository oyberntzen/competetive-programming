#include <cstdio>



int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n+k-1; i++) {
        char c;
        scanf("%c", &c);
        if (c == 'S') {
            int a, b;
            scanf("%d %d", &a, &b);
        }
        if (c == 'Q') {
            int a, d;
            scanf("%d %d", &a, &d);
        }
        if (c == 'C') {
            int d;
            scanf("%d %d", &d);
        }
    }
}