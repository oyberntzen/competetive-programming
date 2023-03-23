#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n < 4) {
        printf("NO SOLUTION\n");
        return 0;
    }

    for (int i = n/2-1; i >= 0; i--) {
        printf("%d %d ", i+1, i+n/2+n%2+1);
        if (n%2 == 1 && i == n/2-1) printf("%d ", n/2+1);
    }
    printf("\n");
}