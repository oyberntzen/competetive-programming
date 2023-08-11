#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ds;
vector<vector<int>> e;
vector<vector<int>> ps;
int parentnum = 18;
void dfs(int a, int b, int d) {
    //printf("%d %d %d\n", a, b, d);
    ds[a] = d;
    ps[a].resize(parentnum);
    ps[a][0] = b;
    for (int i = 1; i < parentnum; i++) {
        ps[a][i] = ps[ps[a][i-1]][i-1];
    }
    for (int i = 0; i < int(e[a].size()); i++) {
        if (e[a][i] != b) {
            dfs(e[a][i], a, d+1);
        }
    }
}

int parentd(int a, int d) {
    int j = 1;
    for (int i = 0; i < parentnum-1; i++) {
        j *= 2;
    }
    for (int i = parentnum-1; i >= 0; i--) {
        if (j > d) {
            j /= 2;
            continue;
        }
        a = ps[a][i];
        d -= j;
        j /= 2;
    }
    return a;
}

vector<bool> visit;
vector<int> loop;
int loop_num = 0;
int dfs2(int a, int b) {
    //printf("%d %d\n", a, b);
    if (visit[a]) {
        loop[a] = 0;
        loop_num++;
        return 0;
    }
    visit[a] = true;
    for (int i = 0; i < int(e[a].size()); i++) {
        if (e[a][i] != b) {
            int l = dfs2(e[a][i], a);
            if (l != -1) {
                if (loop[a] == 0) {
                    return -1;
                }
                loop[a] = l+1;
                loop_num++;
                return l+1;
            }
        }
    }
    return -1;
}

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    e.resize(n);
    ds.resize(n);
    ps.resize(n);
    visit.resize(n, false);
    loop.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    if (p == 1) {
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
        return 0;
    }

    dfs2(0, 0);

    if (loop_num == 0) {
        dfs(0, 0, 0);
    }

    for (int i = 0; i < n; i++) {
        //printf("%d: %d\n", i, loop[i]);
        ps[i].resize(parentnum, i);
        if (loop[i] == -1) continue;
        for (int j = 0; j < int(e[i].size()); j++) {
            if (loop[e[i][j]] != -1) continue;
            dfs(e[i][j], i, 1);
        }
    }


    /*for (int i = 0; i < n; i++) {
        printf("%d\n", ds[i]);
        printf("p ");
        for (int j = 0; j < 13; j++) {
            printf("%d ", ps[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < p; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        s--;t--;

        int p1 = ps[s][parentnum-1];
        int p2 = ps[t][parentnum-1];
        if (p1 == p2) {
            int deps = ds[s];
            int dept = ds[t];
            if (dept < deps) {
                swap(s, t);
                swap(deps, dept);
            }
            //printf("d %d %d\n", deps, dept);

            int l = dept-deps;
            t = parentd(t, dept-deps);
            //printf("t %d\n", t);
            if (t == s) {
                printf("%d\n", l);
                continue;
            }

            int j = 1;
            for (int k = 0; k < parentnum-1; k++) {
                j *= 2;
            }
            for (int k = parentnum-1; k >= 0; k--) {
                //printf("%d (%d) %d (%d) %d %d\n", s, ps[s][k], t, ps[t][k], k, j);
                if (ps[s][k] == ps[t][k]) {
                    j /= 2;
                    continue;
                }
                s = ps[s][k];
                t = ps[t][k];
                l += j*2;
                j /= 2;
            }
            printf("%d\n", l+2);
            continue;
        }

        int l = ds[s]+ds[t];
        int u1 = loop[p1] - loop[p2];
        if (u1 < 0) u1 += loop_num;
        int u2 = loop[p2] - loop[p1];
        if (u2 < 0) u2 += loop_num;
        l += min(u1, u2);
        printf("%d\n", l);
    }
}