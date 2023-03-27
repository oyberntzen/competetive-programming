#include <cstdio>

int main() {

    int n;
    scanf("%d", &n);

    for (long long k = 1; k <= n; k++) {
        long long combinations = k*k*k*k/2 - 9*k*k/2 + 12*k - 8;

        printf("%lld\n", combinations);
    }
}