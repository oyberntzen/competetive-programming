#include <iostream>
#include <string>

using namespace std;

#define NUM_RECORDS 3

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int current = 0;
    int records[NUM_RECORDS] = {0, 0, 0};
    while (getline(cin, line)) {
        if (line == "") {
            int record_dif = 0;
            int record_i = 0;
            for (int i = 0; i < NUM_RECORDS; i++) {
                if (current-records[i] > record_dif) {
                    record_dif = current-records[i];
                    record_i = i;
                }
            }
            if (record_dif > 0) {
                records[record_i] = current;
            }
            current = 0;
        } else {
            current += atoi(line.c_str());
        }
    }

    int sum = 0;
    for (int i = 0; i < NUM_RECORDS; i++) {
        sum += records[i];
    }
    cout << sum << endl;
}