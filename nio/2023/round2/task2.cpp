#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> bergen, oslo;
    bergen.resize(n);
    oslo.resize(n);

    for (int i = 0; i < n; i++) {
        int b, o;
        scanf("%d %d", &b, &o);
        bergen[i] = b;
        oslo[i] = o;
    }

    vector<long> p;
    p.resize(n+3);
    long best = 0;
    for (int i = 1; i < n+3; i++) {
        int bi = i-3;
        long bp = 0;
        if (bi-3 >= 0) bp = p[bi-3] + bergen[bi];

        int oi = i-2;
        long op = 0;
        if (oi-2 >= 0 && oi < n) op = p[oi-2] + oslo[oi];

        p[i] = max(bp, max(op, p[i-1]));
        best = max(best, p[i]);
    }
    printf("%ld\n", best);
}