#include <cstdio>

bool found[200000];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        int m;
        scanf("%d", &m);
        found[m-1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!found[i]) {
            printf("%d\n", i+1);
            break;
        }
    }
}