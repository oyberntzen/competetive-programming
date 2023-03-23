#include <bits/stdc++.h>

using namespace std;

int people[100000];
vector<tuple<int, int, int>> meets;

int main() {
    int n, m, I, S;
    scanf("%d %d %d %d", &n, &m, &I, &S);

    meets.resize(m);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        meets[i] = make_tuple(d, a, b);
    }
    sort(meets.begin(), meets.end());

    for (int i = 0; i < n; i++) {
        people[i] = -1;
    }
    people[0] = 0;

    queue<int> sick;
    queue<int> inc;
    inc.push(I);
    int last_d = 0;
    int best = 0;
    for (int i = 0; i < m; i++) {
        int a, b, d;
        d = get<0>(meets[i]);
        a = get<1>(meets[i]);
        b = get<2>(meets[i]);

        while (last_d < d) {
            while (inc.size() > 0) {
                if (inc.front() > last_d) break;
                sick.push(inc.front()+S);
                inc.pop();
            }
            while (sick.size() > 0) {
                if (sick.front() > last_d) break;
                sick.pop();
            }
            if (int(sick.size()) > best) best = sick.size();
            //printf("%d: %d\n", last_d, int(sick.size()));
            last_d++;
        }

        //printf("%d: %d (%d) %d (%d)\n", d, a, people[a], b, people[b]);
        if (people[a] == -1 && people[b] != -1 && (people[b]+I+S > d && people[b]+I <= d)) {
            people[a] = d;
            inc.push(d+I);
        }
        if (people[b] == -1 && people[a] != -1 && (people[a]+I+S > d && people[a]+I <= d)) {
            people[b] = d;
            inc.push(d+I);
        }
    }

    while (inc.size() > 0 || sick.size() > 0) {
        while (inc.size() > 0) {
            if (inc.front() > last_d) break;
            sick.push(inc.front()+S);
            inc.pop();
        }
        while (sick.size() > 0) {
            if (sick.front() > last_d) break;
            sick.pop();
        }
        if (int(sick.size()) > best) best = sick.size();
        //printf("%d: %d\n", last_d, int(sick.size()));
        last_d++;
    }

    printf("%d\n", best);
}