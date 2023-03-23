#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;
vector<vector<int>> children;
vector<int> sizes;
vector<vector<int>> work;

int dfs1(int i) {
    int s = 1;
    for (int j = 0; j < children[i].size(); j++) {
        s += dfs1(children[i][j]);
    }
    sizes[i] = s;
    return s;
}

vector<pair<int, int>> current_nodes;
vector<vector<int>> work_stage2;
void dfs2(int i) {
    current_nodes.push_back({sizes[i], i});
    for (int j = 0; j < work[i].size(); j++) {
        for (int l = 0; l < current_nodes.size(); l++) {
            printf("%d, %d\n", current_nodes[l].first, current_nodes[l].second);
        }
        auto k = lower_bound(current_nodes.begin(), current_nodes.end(), make_pair(work[i][j], numeric_limits<int>::max()), greater<pair<int,int>>());
        work_stage2[current_nodes[k-current_nodes.begin()].second].push_back(work[i][j]);
        printf("dfs2: %d %d %d\n", i, current_nodes[k-current_nodes.begin()].second, work[i][j]);
    }
    for (int j = 0; j < children[i].size(); j++) {
        dfs2(children[i][j]);
    }
    
    current_nodes.pop_back();
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    parents.resize(n);
    children.resize(n);
    for (int i = 1; i < n; i++) {
        int l;
        scanf("%d", &l);
        parents[i] = l;
        children[l].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        sort(children[i].begin(), children[i].end());
    }

    sizes.resize(n);
    dfs1(0);

    work.resize(n);
    for (int i = 0; i < m; i++) {
        int w, g;
        scanf("%d %d", &w, &g);
        work[w].push_back(g);
    }
    
    work_stage2.resize(n);
    dfs2(0);
}