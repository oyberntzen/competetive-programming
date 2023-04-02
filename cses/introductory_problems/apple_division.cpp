#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> p;
ll s;

ll best = 100000000000;
ll current = 0;

void search(int i) {
    if (current > s/2 && abs(current-(s-current)) >= best) return;
    best = min(abs(current-(s-current)), best);
    if (i >= int(p.size())) return;
    search(i+1);
    current += p[i];
    search(i+1);
    current -= p[i];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ll pi;
        scanf("%lld", &pi);
        s += pi;
        p.push_back(pi);
    }

    sort(p.begin(), p.end());

    search(0);
    printf("%lld\n", best);
}