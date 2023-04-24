#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> p;
    for (int i = 0; i < n; i++) {
        int pi;
        scanf("%d", &pi);

        p.push_back(pi);
    }

    sort(p.begin(), p.end());
    int target = p[n/2];
    
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(p[i]-target);
    }

    printf("%lld\n", cost);
}

