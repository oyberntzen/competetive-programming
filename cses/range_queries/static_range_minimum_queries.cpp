#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<int> x[18];
    for (int i = 0; i < 18; i++) {
        x[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        int xi;
        scanf("%d", &xi);
        x[0][i] = xi;
    }

    vector<int> p = {1};
    int m = 2;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < n; j++) {
            if (j + m <= n) {
                x[i+1][j] = min(x[i][j], x[i][j+m/2]);
                //printf("%d %d: %d (%d %d)\n", i+1, j, x[i+1][j], x[i][j], x[i][j+m/2]);
            }
        }
        p.push_back(m);
        m *= 2;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        int y = 2000000000;
        while (b > a) {
            int l = upper_bound(p.begin(), p.end(), b-a)-p.begin()-1;
            if (l >= int(p.size())) l = int(p.size())-1;
            y = min(y, x[l][a]);
            //printf("%d %d: %d (%d) %d\n", a, b, l, p[l], y);
            a += p[l];
        }
        printf("%d\n", y);
    }
}
