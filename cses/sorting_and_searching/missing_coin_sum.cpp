#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> x;
    for (int i = 0; i < n; i++) {
        int xi;
        scanf("%d", &xi);
        x.push_back(xi);
    }

    sort(x.begin(), x.end());

    long long y = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] > y) {
            break;
        } else {
            y += x[i];
        }
    }
    printf("%lld\n", y);
}
