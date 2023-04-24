#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        p.push_back(make_pair(a, 0));
        p.push_back(make_pair(b, 1));
    }

    sort(p.begin(), p.end());

    int cust = 0;
    int best = 0;
    for (int i = 0; i < n*2; i++) {
        if (p[i].second == 0) cust++;
        else cust--;
        best = max(best, cust);
    }

    printf("%d\n", best);
}


