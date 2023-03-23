#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    int last = 0;
    long long num = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x < last) {
            num += last-x;
            x = last;
        }
        last = x;
    }
    printf("%lld\n", num);
}