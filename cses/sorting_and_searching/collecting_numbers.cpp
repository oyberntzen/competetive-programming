#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        int xi;
        scanf("%d", &xi);
        xi--;
        x[xi] = i;
    }

    int rounds = 1;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] < last) rounds++;
        last = x[i];
    }

    printf("%d\n", rounds);
}
