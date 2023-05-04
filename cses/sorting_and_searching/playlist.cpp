#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> k1;
    vector<pair<int, int>> k2;
    for (int i = 0; i < n; i++) {
        int ki;
        scanf("%d", &ki);
        k1.push_back(ki);
        k2.push_back(make_pair(ki, i));
    }

    sort(k2.begin(), k2.end());

    vector<vector<int>> k3;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (k2[i].first != last) {
            k3.push_back({});
        }
        k3[k3.size()-1].push_back(k2[i].second);
        //printf("u: %d\n", k2[i].second);
        k1[k2[i].second] = k3.size()-1;
        last = k2[i].first;
    }
    vector<int> ind(k3.size());

    int b = 0;
    int best = 0;
    ind[k1[0]]++;
    for (int a = 0; a < n; a++) {
        if (k1[a] != k1[b] || a == b)
        while (b < n) {
            b++;
            //printf("a: %d\n", b);
            if (b == n) break;
            //printf("t: %d %d %d %d %d\n", a, b, k1[b], ind[k1[b]], k3[k1[b]][ind[k1[b]]-1]);
            if (ind[k1[b]] > 0) {
                if (k3[k1[b]][ind[k1[b]]-1] >= a) {
                    ind[k1[b]]++;
                    //printf("d: %d %d %d %d\n", b, k1[b], ind[k1[b]], k3[k1[b]][ind[k1[b]-1]]);
                    break;
                }
            }
            ind[k1[b]]++;
        }
        best = max(best, b-a);
        //printf("%d %d %d %d\n", a, b, b-a, best);
    }
    printf("%d\n", best);

}
