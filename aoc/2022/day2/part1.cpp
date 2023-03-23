#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    freopen("input.txt", "r", stdin);

    int score = 0;
    while (getline(cin, line)) {
        char opponent = line[0];
        char me = line[2];

        int current_score = me - 'X' + 1;

        int difference = (((opponent - 'A') - (me - 'X')) + 3) % 3;

        if (difference == 0) {
            current_score += 3;
        } else if (difference == 1) {
            current_score += 0;
        } else {
            current_score += 6;
        }

        score += current_score;
    }
    cout << score << endl;
}