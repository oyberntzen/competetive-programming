#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        int t, v;
        scanf("%d %d", &t, &v);
        input.push_back(make_pair(t, v));
    }
    sort(input.begin(), input.end());

    priority_queue<int, vector<int>, greater<int>> waiting;
    multiset<int> filling;
    ll wait_time = 0;
    for (int i = 0; i < n; i++) {
        int t = input[i].first;
        int v = input[i].second;
        int lt = 0;
        if (i > 0) {
            lt = input[i-1].first;
        }

        while (!filling.empty()) {
            if (*filling.begin() > t) break;
            wait_time += ll(*filling.begin() - lt) * ll(waiting.size());
            lt = *filling.begin();
            filling.erase(filling.begin());
            if (waiting.size() > 0) {
                filling.insert(waiting.top()+lt);
                waiting.pop();
            }
        }
        wait_time += ll(t - lt) * ll(waiting.size());
        lt = t;

        waiting.push(v);
        filling.insert(waiting.top()+t);
        waiting.pop();
        if (filling.size() > k) {
            auto last = filling.end();
            last--;
            waiting.push(*last-t);
            filling.erase(last);
        }
    }

    int lt = input[input.size()-1].first;
    while (!filling.empty()) {
        wait_time += ll(*filling.begin() - lt) * ll(waiting.size());
        lt = *filling.begin();
        filling.erase(filling.begin());
        if (waiting.size() > 0) {
            filling.insert(waiting.top()+lt);
            waiting.pop();
        }
    }

    printf("%lld\n", wait_time);
}