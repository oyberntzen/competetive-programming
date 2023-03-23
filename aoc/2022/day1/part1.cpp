#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int current = 0;
    int record = 0;
    while (getline(cin, line)) {
        if (line == "") {
            if (current > record) {
                record = current;
            }
            current = 0;
        } else {
            current += atoi(line.c_str());
        }
    }
    cout << record << endl;
}