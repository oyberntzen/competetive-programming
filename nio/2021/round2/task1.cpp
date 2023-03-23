#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int N, K, G;
    scanf("%d %d %d", &N, &K, &G);

    vector<int> X;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        X.push_back(x - G);
    }

    sort(X.begin(), X.end());

    
    ll dist = 0;
    for (int i = 0; X[i] < 0;) {
        dist += -X[i];
        int j = 0;
        for (; j < K-1 && X[i+j+1] < 0; j++) {
            dist += -X[i+j] + X[i+j+1];
        }
        dist += -X[i+j];
        i += j+1;
    }
    for (int i = X.size()-1; X[i] > 0;) {
        dist += X[i];
        int j = 0;
        for (; j < K-1 && X[i-j-1] > 0; j++) {
            dist += X[i-j] - X[i-j-1];
        }
        dist += X[i-j];
        i -= j+1;
    }
    cout << dist << endl;
}