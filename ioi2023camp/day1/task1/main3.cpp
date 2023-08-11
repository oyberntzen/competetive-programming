#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

#define NUM_RAND 200

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<vector<int>> d(NUM_RAND);
    queue<int> q;
    vector<bool> used(n);
    for (int i = 0; i < NUM_RAND; i++) {
        used.clear();
        used.resize(n, false);
        d[i].resize(n);
        int s = rand() % n;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : e[v]) {
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                    d[i][u] = d[i][v] + 1;
                }
            }
        }
    }

    for (int i = 0; i < p; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        s--;t--;

        int shortest = 1000000;
        for (int j = 0; j < NUM_RAND; j++) {
            int dist = d[j][s] + d[j][t];
            shortest = min(shortest, dist);
        }
        printf("%d\n", shortest);
    }
}