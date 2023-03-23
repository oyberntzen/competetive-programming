#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define WIDTH 700
#define HEIGHT 200

int main() {
    freopen("input.txt", "r", stdin);

    bitset<WIDTH*HEIGHT> filled(0);

    string line;
    int max_y;
    while (getline(cin, line)) {
        int start = 0;
        int comma;
        int lastx = -1;
        int lasty = -1;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ',') {
                comma = i;
            }
            if (line[i] == '>' || i == line.size()-1) {
                if (i == line.size()-1) i += 3;
                int x = stoi(line.substr(start, comma-start));
                int y = stoi(line.substr(comma+1, i-comma-2));

                if (y > max_y) max_y = y;

                if (lastx != -1) {
                    if (lastx != x) {
                        int nx = lastx;
                        while (true) {
                            filled.set(y*WIDTH+nx, true);
                            if (x > lastx) {
                                nx++;
                                if (nx == x+1) break;
                            }
                            else {
                                nx--;
                                if (nx == x-1) break;
                            }
                        }
                    } else {
                        int ny = lasty;
                        while (true) {
                            filled.set(ny*WIDTH+x, true);
                            if (y > lasty) {
                                ny++;
                                if (ny == y+1) break;
                            }
                            else {
                                ny--;
                                if (ny == y-1) break;
                            }
                        }
                    }
                }

                lastx = x;
                lasty = y;
                start = i+2;
            }
        }
    }

    int added = 0;
    while (true) {
        int x = 500;
        int y = 0;
        if (filled.test(y*WIDTH+x)) break;

        while (y < max_y+1) {
            if (x >= WIDTH) printf("%d\n", x);
            if (!filled.test((y+1)*WIDTH+x)) {
                y++;
                continue;
            }
            if (!filled.test((y+1)*WIDTH+x-1)) {
                y++;
                x--;
                continue;
            }
            if (!filled.test((y+1)*WIDTH+x+1)) {
                y++;
                x++;
                continue;
            }
            filled.set(y*WIDTH+x, true);
            break;
        }
        if (y == max_y+1) filled.set(y*WIDTH+x, true);
        added++;
    }
    printf("%d\n", added);
}