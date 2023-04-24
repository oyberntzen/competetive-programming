#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);
        a.push_back(make_pair(ai, i+1));
    }
    sort(a.begin(), a.end());

    int s = 0;
    int e = a.size()-1;
    while (s != e) {
        int sum = a[s].first+a[e].first;
        if (sum == x) {
            printf("%d %d\n", a[s].second, a[e].second);
            return 0;
        } else if (sum < x) {
            s++;
        } else {
            e--;
        }
    }

    printf("IMPOSSIBLE\n");
}
