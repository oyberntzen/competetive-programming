#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    freopen("data.txt", "r", stdin);

    vector<int> xs;
    vector<int> ys;
    int x, y;

    int i = 0;
    int minX = INT32_MAX;
    int minI = 0;
    while (scanf("%d %d", &x, &y) != EOF) {
        xs.push_back(x);
        ys.push_back(y);
        
        if (x < minX) {
            minX = x;
            minI = i;
        }

        i++;
    }

    int ci = minI;
    int cx = xs[ci];
    int cy = ys[ci];
    vector<int> pi;
    double v1x = 0;
    double v1y = -1;

    printf("%d %d %d\n", ci, cx, cy);

    bool progress = false;
    i = 0;
    while ((cx != minX) || (!progress)) {
        double bestCos = -1;
        int bestI = 0;
        for (int i = 0; i < xs.size(); i++) {
            if (i != ci) {
                double v2x = xs[i] - cx;
                double v2y = ys[i] - cy;
                double root = sqrt(v1x*v1x+v1y*v1y)*sqrt(v2x*v2x+v2y*v2y);
                double currentCos = v1x*v2x/root + v1y*v2y/root;
                if (currentCos > bestCos) {
                    bestCos = currentCos;
                    bestI = i;
                }
            }
        }
        printf("%f\n", bestCos);

        pi.push_back(ci);
        bool finished = false;
        for (int i = 0; i < pi.size(); i++) {
            if (bestI == pi[i]) {
                finished = true;
                pi.push_back(bestI);
                printf("%d\n", bestI);
                break;
            }
        }
        if (finished) break;

        ci = bestI;
        v1x = xs[ci] - cx;
        v1y = ys[ci] - cy;
        cx = xs[ci];
        cy = ys[ci];
        
        printf("%d %d %d\n", ci, cx, cy);
        if (i == 10000) {
            break;
        }
        i++;
    }

    printf("%d\n", int(pi.size()));

    long area = 0;
    for (int i = 0; i < pi.size()-1; i++) {
        area += long(xs[pi[i]])*long(ys[pi[i+1]]) - long(ys[pi[i]])*long(xs[pi[i+1]]);
    }
    area = area/2;
    printf("%ld\n", area);
}