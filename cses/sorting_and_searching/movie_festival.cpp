#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        movies.push_back(make_pair(b, a));
    }

    sort(movies.begin(), movies.end());

    int num = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].second >= t) {
            num++;
            t = movies[i].first;
        }
    }
    printf("%d\n", num);
}
