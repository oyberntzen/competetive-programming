#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<ll> pre_sum = {0};
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        pre_sum.push_back(pre_sum[i]+x);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ll s = pre_sum[b]-pre_sum[a-1];
        printf("%lld\n", s);
    }
}
