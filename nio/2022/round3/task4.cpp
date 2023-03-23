#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int v = 0;
    int h = 0;
    for (int i = 0; i < m; i++) {
        int x;
        char s;
        scanf("%d %c", &x, &s);
        if (s == 'V') {
            printf("%d\n", v);
            v++;
        } else {
            printf("%d\n", v+h);
            h++;
        }
    }
}