#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        ll x, y;
        scanf("%lld %lld", &y, &x);

        ll layer = max(x, y);
        ll value = layer*layer;
        if (x > y) {
            if (layer%2 == 0) {
                value -= (x-1) + (layer-y);
            } else {
                value -= y-1;
            }
        } else {
            if (layer%2 == 1) {
                value -= (y-1) + (layer-x);
            } else {
                value -= x-1;
            }
        }
        printf("%lld\n", value);
    }
}