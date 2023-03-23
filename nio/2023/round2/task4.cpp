#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

int n, m, k, p;

vector<pair<int, int>> nodes;
vector<bool> visited;
vector<tuple<int, int, int>> edges;
vector<vector<int>> netnodes;

pair<int, int> dfs(int i) {
    //printf("%d\n", i);
    visited[i] = true;
    if (nodes[i].first != -1) {
        if (nodes[i].first < k) {
            return {nodes[i].first, 1};
        }
        if (!visited[nodes[i].first]) {
            pair<int, int> result = dfs(nodes[i].first);
            result.second++;
            return result;
        }
    }
    if (nodes[i].second != -1) {
        if (nodes[i].second < k) {
            return {nodes[i].second, 1};
        }
        if (!visited[nodes[i].second]) {
            pair<int, int> result = dfs(nodes[i].second);
            result.second++;
            return result;
        }
    }
    if (nodes[i].first != -1 && nodes[i].second != -1) {
        return {-2, 1};
    }
    return {-1, 1};
}

vector<int> antivirus;
int best = 1000000;
void dfs2(int i) {
    //printf("%d\n", i);

    if (i == k) {
        int score = 0;
        for (int j = 0; j < k; j++) {
            if (antivirus[j] == 1) score++;
            //printf("%d ", antivirus[j]);
        }
        //printf("\n");
        for (int j = 0; j < edges.size(); j++) {
            auto edge = edges[j];
            int u = get<0>(edge);
            int v = get<1>(edge);
            int length = get<2>(edge);
            bool u_have = true;
            bool v_have = true;
            if (u != -1) if (antivirus[u] == -1) u_have = false;
            if (v != -1) if (antivirus[v] == -1) v_have = false;
            if (!u_have && !v_have) {
                score += length/2 + 1;
            } else if (u_have && v_have) {
                score += length/2;
            } else {
                score += (length+1)/2;
            }
        }
        //printf("b %d\n", score);
        best = min(best, score);
    } else {
        bool valid = true;
        for (int j = 0; j < netnodes[i].size(); j++) {
            if (antivirus[netnodes[i][j]] == -1) {
                valid = false;
                break;
            }
        }
        if (valid) {
            antivirus[i] = -1;
            dfs2(i+1);
        }
        antivirus[i] = 1;
        dfs2(i+1);
        antivirus[i] = 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d %d %d %d", &n, &m, &k, &p);

    nodes = vector<pair<int, int>>(n, {-1, -1});

    netnodes.resize(k);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < k && v < k) {
            netnodes[u].push_back(v);
            netnodes[v].push_back(u);
            continue;
        }

        if (nodes[u].first == -1) nodes[u].first = v;
        else if (nodes[u].second == -1) nodes[u].second = v;
        if (nodes[v].first == -1) nodes[v].first = u;
        else if (nodes[v].second == -1) nodes[v].second = u;
    }

    for (int i = 0; i < p; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        netnodes[u].push_back(v);
        netnodes[v].push_back(u);
    }

    int num = 0;

    visited.resize(n);
    for (int i = k; i < n; i++) {
        //printf("%d\n", i);
        if (!visited[i]) {
            visited[i] = true;
            int length = 1;
            int u = -1;
            if (nodes[i].first != -1) {
                if (nodes[i].first < k) u = nodes[i].first;
                else {
                    pair<int, int> result = dfs(nodes[i].first);
                    u = result.first;
                    length += result.second;
                    if (u == -2) {
                        num += (length+1)/2;
                        continue;
                    }
                }
            }
            int v = -1;
            if (nodes[i].second != -1) {
                if (nodes[i].second < k) v = nodes[i].second;
                else {
                    pair<int, int> result = dfs(nodes[i].second);
                    v = result.first;
                    length += result.second;
                    if (v == -2) {
                        num += (length+1)/2;
                        continue;
                    }
                }
            }
            if (u == -1 && v == -1) {
                num += length/2;
                continue;
            }
            edges.push_back(make_tuple(u, v, length));
            //printf("%d %d %d\n", u, v, length);
        }
    }

    antivirus.resize(k);
    dfs2(0);

    printf("%d\n", num+best);
}