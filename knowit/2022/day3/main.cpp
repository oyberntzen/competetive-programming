#include <iostream>
#include <string>

using namespace std;

#define PAPER_WIDTH 110

int rollLength(int length, int width, int height) {
    if (width*2 + height*2 <= PAPER_WIDTH) {
        return length + height;
    }

    if (width + height <= PAPER_WIDTH) {
        return length*2 + height*2;
    }

    return -1;
}

int main() {
    freopen("pakker.csv", "r", stdin);

    int total = 0;
    string line;
    getline(cin, line);
    while (getline(cin, line)) {
        int a, b, c;
        int i = 0;
        for (; i < line.size(); i++) {
            if (line[i] == ',') {
                a = atoi(line.substr(0, i).c_str());
                break;
            }
        }
        for (int j = i; j < line.size(); j++) {
            if (line[j] == ',') {
                b = atoi(line.substr(i+1, j-i-1).c_str());
                c = atoi(line.substr(j+1, line.size()-j-1).c_str());
                break;
            }
        }

        int lengths[6];
        lengths[0] = rollLength(a, b, c);
        lengths[1] = rollLength(a, c, b);
        lengths[2] = rollLength(b, a, c);
        lengths[3] = rollLength(b, c, a);
        lengths[4] = rollLength(c, a, b);
        lengths[5] = rollLength(c, b, a);

        int record = INT_MAX;
        for (int i = 0; i < 6; i++) {
            if (lengths[i] != -1 && lengths[i] < record) {
                record = lengths[i];
            }
        }
        total += record;
    }
    cout << total << endl;
}

