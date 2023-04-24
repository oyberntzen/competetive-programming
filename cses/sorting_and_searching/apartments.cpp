#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);
        a.push_back(ai);
    }

    vector<int> b;
    for (int i = 0; i < m; i++) {
        int bi;
        scanf("%d", &bi);
        b.push_back(bi);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ai = 0;
    int bi = 0;
    int num = 0;
    while (ai < int(a.size()) && bi < int(b.size())) {
        if (a[ai] < b[bi]-k) ai++;
        else if (a[ai] > b[bi]+k) bi++;
        else {num++; ai++; bi++;}
    }
    printf("%d\n", num);
}
