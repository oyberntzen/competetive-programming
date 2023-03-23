#include <stdlib.h>
#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    vector<int> cards1;
    vector<int> cards2;
    for (int num = 4; true; num += 2) {
        cards1.resize(num);
        cards2.resize(num);
        for (int i = 0; i < num; i++) {
            cards1[i] = i;
        }

        int shuffles;
        bool valid = false;
        for (shuffles = 0; shuffles < 13; shuffles++) {
            for (int i = 0; i < num; i++) {
                if (i % 2 == 0) {
                    cards2[i] = cards1[i/2];
                } else {
                    cards2[i] = cards1[i/2+num/2];
                }
            }

            valid = true;
            for (int i = 0; i < num; i++) {
                if (cards2[i] != i) {
                    valid = false;
                }
                cards1[i] = cards2[i];
            }
            if (valid == true && shuffles < 12) {
                valid = false;
                break;
            }
        }

        if (num % 1000 == 0) {
            printf("%d\n", num);
        }

        if (valid) {
            printf("%d\n", num);
            break;
        }
    }

    auto end = chrono::high_resolution_clock::now();

    cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" <<  endl;
}