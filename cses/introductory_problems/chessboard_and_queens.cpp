#include <iostream>
#include <string>
using namespace std;

bool map[64];
bool queens[64];
int num = 0;
int combs = 0;
void search(int i) {
    if (map[i]) return;
    int x0 = i % 8;
    int y0 = i / 8;
    for (int x = 0; x < 8; x++) {
        if (queens[y0*8+x]) return;
    }
    for (int y = 0; y < 8; y++) {
        if (queens[y*8+x0]) return;
    }
    for (int x = 0; x < 8; x++) {
        int y = y0+(x-x0);
        if (y < 0 || y >= 8) continue;
        if (queens[y*8+x]) return;
    }
    for (int x = 0; x < 8; x++) {
        int y = y0-(x-x0);
        if (y < 0 || y >= 8) continue;
        if (queens[y*8+x]) return;
    }
    queens[i] = true;
    num++;
    if (num == 8) {
        combs++;
    }
    for (int j = i+1; j < 64; j++) {
        search(j);
    }
    queens[i] = false;
    num--;
}

int main() {
    string s;
    for (int i = 0; i < 8; i++) {
        getline(cin, s);
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') map[i*8+j] = true;
        }
    }
    for (int i = 0; i < 64; i++) search(i);
    printf("%d\n", combs);
}