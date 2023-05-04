#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> t;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        auto j = lower_bound(t.begin(), t.end(), k+1);
        if (j == t.end()) t.push_back(k);
        else t[j-t.begin()] = k;
    }
    printf("%d\n", int(t.size()));
}
