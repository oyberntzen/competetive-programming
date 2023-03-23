#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    char last = ' ';
    int best = 0;
    int current = 0;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == last) {
            current++;
        } else {
            current = 1;
        }
        best = max(best, current);
        last = s[i];
    }
    printf("%d\n", best);
}