#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    long tot = 0;
    string line;
    while (getline(cin, line)) {
        long mul = 1;
        long num = 0;
        for (int i = line.size()-1; i >= 0; i--) {
            if (line[i] == '=') num -= mul*2;
            else if (line[i] == '-') num -= mul;
            else if (line[i] == '1') num += mul;
            else if (line[i] == '2') num += mul*2;
            mul *= 5;
        }
        tot += num;
    }

    vector<char> chars;
    for (int i = 0; tot != 0; i++) {
        long num = tot % 5;
        if (num < 0) num += 5;
        if (num == 2) {
            chars.push_back('2');
            tot -= 2;
        } else if (num == 1) {
            chars.push_back('1');
            tot--;
        } else if (num == 0) {
            chars.push_back('0');
        } else if (num == 4) {
            chars.push_back('-');
            tot++;
        } else if (num == 3) {
            chars.push_back('=');
            tot += 2;
        }
        tot /= 5;
    }
    for (int i = chars.size()-1; i >= 0; i--) {
        printf("%c", chars[i]);
    }
    printf("\n");
}