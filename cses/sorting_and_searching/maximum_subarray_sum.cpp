#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    ll sum = -3000000000;
    ll best = -3000000000;
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);

        sum = max(sum+x, x);
        best = max(best, sum);
    }

    printf("%lld\n", best);
}
