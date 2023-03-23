#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int k, n;
    scanf("%d %d", &k, &n);

    int a = 0;
    int b = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
        char s;
        int t;
        scanf("%c%d", &s, &t);
        if (s == '-') t = -t;
        a += t;
        b += t;
        a = max(a, 0);
        b = min(b, k);
        if (b < 0) {
            a = 0;
            b = k+t;
            num++;
        }
        if (a > k) {
            b = k;
            a = t;
            num++;
        }
    }
    printf("%d\n", num);
}