#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <bitset>
#include <queue>

using namespace std;

#define SIZE 250

int n;
int h[SIZE*SIZE];
bitset<SIZE*SIZE> to(0);
bitset<SIZE*SIZE> from(0);

double dist_between(int fx, int fy, int tx, int ty) {
    return 10.0*pow(2.0, (h[ty*n+tx]-h[fy*n+fx])/100.0);
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int ch;
            scanf("%d", &ch);
            h[y*n+x] = ch;
        }
    }
    
    string line;
    getline(cin, line);
    for (int y = 0; y < n; y++) {
        getline(cin, line);
        for (int x = 0; x < n; x++) {
            if (line[x] == 'F' || line[x] == '*') {
                from[y*n+x] = true;
            }
            if (line[x] == 'T' || line[x] == '*') {
                to[y*n+x] = true;
            }
        }
    }

    bitset<SIZE*SIZE*2> processed(0);
    double distance[SIZE*SIZE*2];
    priority_queue<pair<double, int>> q;
    for (int i = 0; i < n*n*2; i++) distance[i] = INFINITY;
    distance[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        if (a == n*n-1 || (a == n*n*2-1 && to[n*n-1])) {
            printf("%f\n", distance[a]);
            break;
        }
        pair<int, int> adjacent[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ax = a % n;
        int ay = (a % (n*n)) / n;
        for (int i = 0; i < 4; i++) {
            int bx = ax + adjacent[i].first;
            int by = ay + adjacent[i].second;
            if (bx < 0 || bx >= n || by < 0 || by >= n) continue;
            if (a < n*n || to[a%(n*n)]) {
                int b = by*n + bx;
                double w = 50;
                if (distance[a]+w < distance[b]) {
                    distance[b] = distance[a]+w;
                    q.push({-distance[b], b});
                }
            }
            if (a >= n*n || from[a%(n*n)]) {
                int b = by*n + bx + n*n;
                double w = dist_between(ax, ay, bx, by);
                if (distance[a]+w < distance[b]) {
                    distance[b] = distance[a]+w;
                    q.push({-distance[b], b});
                }
            }
        }
    }
}