#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> hs;
vector<vector<int>> wh;
int l, b;

void dfs(int x, int y, int h) {
    if (x < 0 || x >= b) return;
    if (y < 0 || y >= l) return;
    h = max(hs[y][x], h);
    if (h >= wh[y][x]) return;
    wh[y][x] = h;
    dfs(x-1, y, h);
    dfs(x+1, y, h);
    dfs(x, y-1, h);
    dfs(x, y+1, h);
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &l, &b);
    
    hs.resize(l);
    wh.resize(l);
    for (int y = 0; y < l; y++) {
        hs[y].resize(b);
        wh[y].resize(b);
        for (int x = 0; x < b; x++) {
            int h;
            scanf("%d", &h);
            hs[y][x] = h;
            wh[y][x] = 1001;
        }
    }

    for (int y = 0; y < l; y++) {
        for (int x = 0; x < b; x++) {
            int a;
            scanf("%d", &a);
            if (a == 1) {
                dfs(x, y, hs[y][x]);
            }
        }
    }

    int num = 0;
    for (int y = 0; y < l; y++) {
        for (int x = 0; x < b; x++) {
            if (hs[y][x] != wh[y][x]) {
                num++;
            }
        }
    }
    printf("%d\n", num);
}