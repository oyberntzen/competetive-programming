#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<int> c(n);
    vector<vector<int>> next(m+1);
    for (int i = 0; i < n; i++) {
        int ci;
        scanf("%d", &ci);
        c[i] = ci;
        next[ci].push_back(i);
    }
    
    int num = 0;
    vector<int> g(m+1, -1);
    map<int, pair<int, int>> r;
    for (int i = 0; i < k; i++) {
        r[n+i] = make_pair(i, 0);
    }

    for (int i = 0; i < n; i++) {
        if (g[c[i]] != -1) {
            r.erase(i);
            auto v = lower_bound(next[c[i]].begin(), next[c[i]].end(), i+1);
            if (v == next[c[i]].end()) r[n+g[c[i]]] = make_pair(g[c[i]], c[i]);
            else r[*v] = make_pair(g[c[i]], c[i]);
            continue;
        }
        auto last = r.end();
        last--;
        auto a = *last;
        r.erase(last);
        g[a.second.second] = -1;
        g[c[i]] = a.second.first;
        auto v = lower_bound(next[c[i]].begin(), next[c[i]].end(), i+1);
        if (v == next[c[i]].end()) r[n+g[c[i]]] = make_pair(g[c[i]], c[i]);
        else r[*v] = make_pair(g[c[i]], c[i]);
        num++;
    }
    printf("%d\n", num);
}