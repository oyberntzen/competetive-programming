#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n, t, k;
vector<vector<int>> c;
vector<vector<int>> cache;

int dfs(int i, int r) {
    if (i >= n) return 0;
    if (cache[i][r] != -1) return cache[i][r];
    int best = 0;
    for (int j = i; j < n-r; j++) {
        for (int l = 0; l < r; l++) {
            if (l != 0) if (c[l][j] <= c[l-1][j]) continue;
            int score = dfs(j+l+2, r-l-1)+c[l][j];
            if (score > best) best = score;
        }
    }
    cache[i][r] = best;
    return best;
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &t, &k);
    c.resize(t);
    for (int i = 0; i < t; i++) {
        c[i].resize(n-i-1);
    }
    for (int i = 0; i < k; i++) {
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        for (int j = abs(a-b)-1; j < t; j++) {
            for (int k = 0; k < j+2-abs(a-b); k++) {
                if (min(a,b)-k < 0) break;
                if (min(a,b)-k >= c[j].size()) {
                    k = min(a,b)-c[j].size();
                    continue;
                }
                c[j][min(a,b)-k] += p;
            }
        }
    }

    cache.resize(n);
    for (int i = 0; i < n; i++) {
        cache[i].resize(t+1);
        for (int j = 0; j < t+1; j++) {
            cache[i][j] = -1;
        }
    }
    
    printf("%d\n", dfs(0, t));
}