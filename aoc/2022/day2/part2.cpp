#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    freopen("input.txt", "r", stdin);

    int score = 0;
    while (getline(cin, line)) {
        char opponent = line[0];
        char result = line[2];

        int current_score = (result - 'X') * 3;
        int difference;
        if (result == 'X') {
            difference = 2;
        } else if (result == 'Y') {
            difference = 0;
        } else if (result == 'Z') {
            difference = 1;
        }

        int me = (opponent - 'A' + difference) % 3;
        current_score += me + 1;
        score += current_score;
    }
    cout << score << endl;
}