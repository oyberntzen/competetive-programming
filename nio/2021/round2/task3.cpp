#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<vector<pair<int, int> >, bool> > s;
vector<ll> q;

ll traverse(int u) {
    if (q[u] != -1) {
        return q[u];
    }
    ll best = 0;
    for (int i = 0; i < s[u].first.size(); i++) {
        best = max(best, traverse(s[u].first[i].first) + ll(s[u].first[i].second));
    }
    q[u] = best;
    return q[u];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        s.push_back(pair<vector<pair<int, int> >, bool>(vector<pair<int, int> >(), false));
        q.push_back(-1);
    }
    
    for (int i = 0; i < M; i++) {
        int U, V, L;
        scanf("%d %d %d", &U, &V, &L);
        s[U-1].second = true;
        s[V-1].first.push_back(pair<int, int>(U-1, L));
    }

    ll best = 0;
    for (int i = 0; i < N; i++) {
        if (!s[i].second) {
            best = max(best, traverse(i));
        }
    }
    cout << best << endl;
}

