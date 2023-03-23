#include <iostream>
#include <math.h>

using namespace std;

#define H 16.0
#define R 5.0
#define N 4

pair<double, double> l[N] = {
    pair<double, double>(0.04, 10),
    pair<double, double>(0.04, 15),
    pair<double, double>(0.02, 30),
    pair<double, double>(0.05, 15),
};

int main() {
    double area = M_PI*R*(sqrt(H*H+R*R));
    double cost = 0;
    for (int i = 0; i < N; i++) {
        printf("%f\n", l[i].first*area*l[i].second);
        cost += l[i].first*area*l[i].second;
    }
    printf("%f\n", cost);
}