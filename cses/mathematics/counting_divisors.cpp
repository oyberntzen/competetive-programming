#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int num = 0;
        for (int j = 1; j*j <= x; j++) {
            if (x % j == 0) {
                num += 2;
                if (j*j == x) num--;
            }
        }
        printf("%d\n", num);
    }
}