#include <cstdio>
#include <vector>
using namespace std;

vector<bool> used;
int n, k;
vector<int> a;
bool dfs(int i, bool single) {
    //printf("i: %d\n", i);
    if (i == n) return true;
    if (i == n-1) return false;
    int brush = a[i]*k+a[i+1];
    //printf("a %d (%d) %d (%d) %d\n", a[i], i, a[i+1], i+1, k);
    //printf("b %d %d\n", brush, int(used[brush]));
    if (used[brush]) return false;

    used[brush] = true;
    if (dfs(i+2, false)) return true;
    if (!single) if (dfs(i+1, true)) return true;
    used[brush] = false;
    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test = 0; test < t; test++) {
        used.clear();
        a.clear();
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            int ai;
            scanf("%d", &ai);
            ai--;
            a.push_back(ai);
        }

        used.resize(k*k, false);
        bool result = dfs(0, false);
        if (result) {
            printf("TAK\n");
        } else {
            printf("NIE\n");
        }
    }
}