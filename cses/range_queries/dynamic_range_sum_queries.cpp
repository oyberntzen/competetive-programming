#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    int n, q;
    int l = 262144;
    vector<int> s(l*2);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s[l+i] = x;
    }

    for (int i = l*2-1; i > 1; i--) {
        s[i/2] += s[i];
    }

    for (int i = 0; i < q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a == 
    }
}
