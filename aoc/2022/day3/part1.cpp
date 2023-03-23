#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    string line;
    int sumPriorities = 0;
    while (getline(cin, line)) {
        bool upperCaseUsed[26];
        bool lowerCaseUsed[26];

        for (int i = 0; i < 26; i++) {
            upperCaseUsed[i] = false;
            lowerCaseUsed[i] = false;
        }

        for (int i = 0; i < line.size()/2; i++) {
            if (line[i] >= 'A' && line[i] <= 'Z') {
                upperCaseUsed[line[i]-'A'] = true;
            } else {
                lowerCaseUsed[line[i]-'a'] = true;
            }
        }

        for (int i = line.size()/2; i < line.size(); i++) {
            if (line[i] >= 'A' && line[i] <= 'Z') {
                if (upperCaseUsed[line[i]-'A']) {
                    sumPriorities += line[i]-'A' + 27;
                    break;
                }
            } else {
                if (lowerCaseUsed[line[i]-'a']) {
                    sumPriorities += line[i]-'a' + 1;
                    break;
                }
            }
        }
    }

    cout << sumPriorities << endl;
}