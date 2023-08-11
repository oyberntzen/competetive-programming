#include <cstdio>
#include <vector>
using namespace std;

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

    int s, t;
    scanf("%d %d", &s, &t);
    s--;t--;

    vector<bool> visited(n, false);
    visited[s] = true;
    vector<pair<int, int>> next;
    for (int i = 0; i < int(e[s].size()); i++) {
        next.push_back(make_pair(e[s][i], 1));
    }
    for (int i = 0; i < int(next.size()); i++) {
        if (visited[next[i].first]) continue;
        visited[next[i].first] = true;
        //printf("t %d %d\n", next[i].first, next[i].second);
        if (next[i].first == t) {
            printf("%d\n", next[i].second);
            break;
        }
        for (int j = 0; j < int(e[next[i].first].size()); j++) {
            next.push_back(make_pair(e[next[i].first][j], next[i].second+1));
            //printf("a %d\n", e[next[i].first][j]);
        }
    }
}