#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);

    if (n*(n+1)%4 != 0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");

    ll k = n*(n+1)/4;
    vector<ll> used;
    for (ll i = n; i > 0; i--) {
        if (i <= k) {
            k -= i;
            used.push_back(i);
        }
    }

    printf("%d\n", int(used.size()));
    for (int i = 0; i < int(used.size()); i++) {
        printf("%lld ", used[i]);
    }
    printf("\n");

    printf("%lld\n", n-ll(used.size()));
    int j = 0;
    for (ll i = n; i > 0; i--) {
        if (j < int(used.size())) if (used[j] == i) {
            j++;
            continue;
        }
        printf("%lld ", i);
    }
    printf("\n");
}