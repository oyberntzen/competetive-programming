#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        int xi;
        scanf("%d", &xi);
        xi--;
        x[xi] = i;
        y[i] = xi;
    }

    int rounds = 1;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] < last) rounds++;
        last = x[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;

        if (a > b) swap(a, b);

        //printf("%d %d, %d %d\n", a, b, y[a], y[b]);

        if (y[a] > 0) {
            int c = x[y[a]-1];
            //printf("a: %d\n", c);
            if (c > a && c <= b) rounds--;
        }
        if (y[a] < n-1) {
            int c = x[y[a]+1];
            //printf("b: %d\n", c);
            if (c > a && c <= b) rounds++;
        }
        if (y[b] > 0) {
            int c = x[y[b]-1];
            //printf("c: %d\n", c);
            if (c > a && c < b) rounds++;
        }
        if (y[b] < n-1) {
            int c = x[y[b]+1];
            //printf("d: %d\n", c);
            if (c > a && c < b) rounds--;
        }

        swap(x[y[a]], x[y[b]]);
        swap(y[a], y[b]);
        
        printf("%d\n", rounds);
    }
}
