#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    vector<int> p;
    for (int i = 0; i < n; i++) {
        int pi;
        scanf("%d", &pi);
        p.push_back(pi);
    }

    sort(p.begin(), p.end());

    int a = 0;
    int b = n-1;
    int num = 0;

    while (a <= b) {
        if (p[a]+p[b] <= x) {
            a++;
        }
        b--;
        num++;
        //printf("%d %d\n", a, b);
    }

    printf("%d\n", num);
}
