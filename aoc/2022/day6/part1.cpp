#include <iostream>
#include <string>

using namespace std;

#define LENGTH 4

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    getline(cin, line);

    for (int i = 0; i < line.size()-LENGTH-1; i++) {
        bool valid = true;
        for (int j = 0; j < LENGTH; j++) {
            char character = line[i+j];
            for (int k = j+1; k < LENGTH; k++) {
                if (line[i+k] == character) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            printf("%d\n", i+LENGTH);
            break;
        }
    }
}