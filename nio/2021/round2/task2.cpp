#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int s;
    scanf("%d", &s);
    int s_start = s;

    vector<int> candidates;
    for (int i = 0; i < K-1; i++) {
        int os;
        scanf("%d", &os);
        candidates.push_back(os);
    }

    sort(candidates.begin(), candidates.end(), greater<int>());

    int i = 0;
    
    while (true) {
        int b = 0;
        if (i+1 < candidates.size()) {
            b = candidates[i+1];
        }
        int diff2 = candidates[i] - b;
        if (s+(i+1)*diff2 <= b) {
            s += (i+1)*diff2;
            i += 1;
        } else {
            int h = candidates[i];
            while (true) {
                if (s + i+1 <= h-1) {
                    s += i+1;
                    h--;
                } else {
                    if (h < s) {
                        break;
                    }
                    s += h-s;
                    break;
                }
            }
            break;
        }
    }
    int n = s - s_start;
    cout << n << endl;
}