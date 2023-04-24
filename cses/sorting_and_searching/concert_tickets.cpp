#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> temp_h;
    for (int i = 0; i < n; i++) {
        int hi;
        scanf("%d", &hi);
        temp_h.push_back(hi);
    }
    multiset<int> h(temp_h.begin(), temp_h.end());

    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);

        auto it = h.upper_bound(t);
        if (it == h.begin()) printf("-1\n");
        else {
            printf("%d\n", *(--it));
            h.erase(it);
        }
    }
}
