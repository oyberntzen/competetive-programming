#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct sEdge {
    int fra, til;
    int weight;
    sEdge(int _fra, int _til, int _weight) {
        fra = _fra;
        til = _til;
        weight = _weight;
    }
    bool operator < ( const sEdge & other ) const {
        return weight > other.weight;
    }
};
vector<vector<sEdge> > edge;
priority_queue<sEdge> que;
vector<bool> visited;
void leggTilNaboNoder (int node) {
    for (int i = 0; i < edge[node].size(); i++) {
        int nabo = edge[node][i].til;
        if (!visited[nabo])
            que.push(sEdge(node, nabo, edge[node][i].weight));
    }
}

int main () {
    //freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        edge.push_back(vector<sEdge>());
    }
    int a, b, w;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> w;
        edge[a-1].push_back(sEdge(a-1, b-1, w));
        edge[b-1].push_back(sEdge(b-1, a-1, w));
    }
    visited.assign(N, false);
    visited[0] = true;
    leggTilNaboNoder(0);
    vector<sEdge> minSpanTree;
    long sum = 0;
    while (minSpanTree.size() < N-1) {
        sEdge par = que.top();
        que.pop();
        if (visited[par.til])
            continue;
        visited[par.til] = true ;
        minSpanTree.push_back(par);
        sum += par.weight;
        leggTilNaboNoder(par.til);
    }

    cout << sum*2 << endl;
}