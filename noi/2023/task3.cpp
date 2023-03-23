#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nodes;
vector<int> sizes;
int parent(int u) {
    while (nodes[u] != u) u = nodes[u];
    return u;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    vector<vector<int>> distrust(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        distrust[u].push_back(v);
        distrust[v].push_back(u);
    }

    /*for (int i = 0; i < n; i++) {
        sort(distrust[i].begin(), distrust[i].end());
    } */

    nodes = vector<int>(n);
    sizes = vector<int>(n, 1);
    for (int i = 0; i < n; i++) nodes[i] = i;

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;

        a = parent(a);
        b = parent(b);

        bool done = false;
        for (int i = 0; i < int(distrust[a].size()); i++) {
            if (parent(distrust[a][i]) == b) {
                printf("REFUSE\n");
                done = true;
                break;
            }
        }
        if (done) continue;
        /*
        auto itr = lower_bound(distrust[a].begin(), distrust[a].end(), b);
        if (itr != distrust[a].end()) if (*itr == nodes[b]) {
            printf("REFUSE\n");
            continue;
        }*/

        printf("APPROVE\n");

        int from = a;
        int to = b;
        if (sizes[a] > sizes[b]) {
            to = a;
            from = b;
        }

        nodes[from] = to;
        sizes[to] += sizes[from];
        for (int i = 0; i < int(distrust[from].size()); i++) {
            distrust[to].push_back(distrust[from][i]);
        }
        //sort(distrust[to].begin(), distrust[to].end());
    }
}