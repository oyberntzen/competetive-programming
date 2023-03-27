#include <cstdio>

typedef long long ll;

ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1%m;
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

int main() {
    ll n;
    scanf("%lld", &n);

    ll mod = 1000*1000*1000+7;
    printf("%lld\n", modpow(2, n, mod));
}