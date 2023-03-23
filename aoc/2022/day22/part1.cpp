#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

#define WIDTH 150
#define HEIGHT 200

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    vector<pair<int, int> > ranges;
    bitset<WIDTH*HEIGHT> walls(0);
    int y = 0;
    while (getline(cin, line)) {
        if (line.size() == 0) break;
        int start;
        for (start = 0; line[start] == ' '; start++);
        for (int i = start; i < line.size(); i++) {
            if (line[i] == '#') walls[y*WIDTH+i] = true;
        }
        ranges.push_back({start, line.size()-1});
        y++;
    }

    string ins;
    getline(cin, ins);
    int posx = ranges[0].first;
    int posy = 0;
    int dir = 0;

    int a = -1;
    for (int b = 0; b <= ins.size(); b++) {
        char inst;
        if (b == ins.size()) inst = 'R';
        else inst = ins[b];
        if (inst > 'A') {
            if (a != b-1)  {
                for (int c = stoi(ins.substr(a+1, b-a-1)); c > 0; c--) {
                    int last_posx = posx;
                    int last_posy = posy;
                    if (dir == 0) {
                        posx++;
                        if (posx > ranges[posy].second) posx = ranges[posy].first;
                    }
                    if (dir == 1) {
                        posy++;
                        bool valid = true;
                        if (posy >= ranges.size()) valid = false;
                        else if (posx < ranges[posy].first || posx > ranges[posy].second) valid = false;
                        if (!valid) for (posy = 0; posx < ranges[posy].first || posx > ranges[posy].second; posy++);
                    }
                    if (dir == 2) {
                        posx--;
                        if (posx < ranges[posy].first) posx = ranges[posy].second;
                    }
                    if (dir == 3) {
                        posy--;
                        bool valid = true;
                        if (posy < 0) valid = false;
                        else if (posx < ranges[posy].first || posx > ranges[posy].second) valid = false;
                        if (!valid) for (posy = ranges.size()-1; posx < ranges[posy].first || posx > ranges[posy].second; posy--);
                    }
                    if (walls[posy*WIDTH+posx]) {
                        posx = last_posx;
                        posy = last_posy;
                        break;
                    }
                }
            }
            if (b != ins.size()) {
                if (inst == 'R') dir++;
                else dir--;
                dir %= 4;
                if (dir < 0) dir += 4;
                a = b;
            }
        }
    }
    printf("%d %d %d %d\n", (1000*(posy+1)+4*(posx+1)+dir), posx, posy, dir);
}