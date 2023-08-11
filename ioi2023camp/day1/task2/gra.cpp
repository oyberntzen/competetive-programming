#include "gralib.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n = dajN();
    int k = dajK();

    vector<double> v(n+1, INFINITY);
    v[n] = 0;
    vector<int> p;
    for (int i = n-1; i >= 0; i--) {
        p.clear();
        for (int j = 1; j <= k && i+j <= n; j++) {
            if (i%j == 0) p.push_back(v[i+j]);
        }
        sort(p.begin(), p.end());

        double best = INFINITY;
        double s = 0;
        for (int j = 0; j < int(p.size()); j++) {
            s += p[j];
            double avg = k/(j+1) + s/(j+1);
            if (avg > best) break;
            best = min(best, avg);
        }
        v[i] = best;
        //printf("%d: %f\n", i, best);
    }
    for (int q = 0; q < 100; q++) {
        

        int x = 0;
        while (x != n) {
            int y = nastepna();
            if (x+y <= n && x%y == 0) if (v[x+y] < v[x]) {
                zwieksz();
                x += y;
            }
        }

        koniec();
    }
}
