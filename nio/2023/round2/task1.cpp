#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<pair<int, int>> lightnings;

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        lightnings.push_back({a, b});
    }

    sort(lightnings.begin(), lightnings.end());

    priority_queue<int, vector<int>, greater<int>> current;
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < k) {
            if (lightnings[j].first > i) break;
            current.push(lightnings[j].second);
            j++;
        }
        while (current.size() > 0) {
            if (current.top() >= i) break;
            current.pop();
        }
        if (current.size() % 2 == 0) count++;
    }

    printf("%d\n", count);
}