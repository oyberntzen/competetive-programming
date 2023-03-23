#include <iostream>
#include <bitset>
#include <string>

using namespace std;

#define WIDTH 74
#define HEIGHT 74
#define PADDING 10
#define ROUNDS 10
#define BWIDTH (WIDTH+PADDING*2)
#define BHEIGHT (HEIGHT+PADDING*2)

bitset<BWIDTH*BHEIGHT> elves;
bitset<BWIDTH*BHEIGHT> new_elves;
bitset<BWIDTH*BHEIGHT> moves;
bitset<BWIDTH*BHEIGHT> occupied;

pair<int, int> move_to(int x, int y, int offset) {
    bool squares[8] = {
        elves[(y-1)*(BWIDTH)+(x-1)],
        elves[(y-1)*(BWIDTH)+x],
        elves[(y-1)*(BWIDTH)+(x+1)],
        elves[y*(BWIDTH)+(x+1)],
        elves[(y+1)*(BWIDTH)+(x+1)],
        elves[(y+1)*(BWIDTH)+x],
        elves[(y+1)*(BWIDTH)+(x-1)],
        elves[y*(BWIDTH)+(x-1)],
    };
    bool all_false = true;
    for (int i = 0; i < 8; i++) {
        if (squares[i] == true) all_false = false;
    }
    if (all_false) return {x, y};

    for (int i = offset; i < offset+4; i++) {
        if (i%4 == 0 && !(squares[0] || squares[1] || squares[2])) {
            return {x, y-1};
        }
        if (i%4 == 1 && !(squares[4] || squares[5] || squares[6])) {
            return {x, y+1};
        }
        if (i%4 == 2 && !(squares[6] || squares[7] || squares[0])) {
            return {x-1, y};
        }
        if (i%4 == 3 && !(squares[2] || squares[3] || squares[4])) {
            return {x+1, y};
        }
    }
    return {x, y};
}

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int num = 0;
    for (int y = 0; getline(cin, line); y++) {
        for (int x = 0; x < line.size(); x++) {
            if (line[x] == '#') {
                elves[(y+PADDING)*BWIDTH+(x+PADDING)] = true;
                num++;
                //printf("%d %d\n", y+PADDING, x+PADDING);
            }
        }
    }
    int minx, miny, maxx, maxy;
    for (int round = 0; round < ROUNDS; round++) {
        moves.reset();
        occupied.reset();
        for (int y = 0; y < BHEIGHT; y++) {
            for (int x = 0; x < BWIDTH; x++) {
                if (elves[y*BWIDTH+x]) {
                    auto new_pos = move_to(x, y, round);
                    if (moves[new_pos.second*BWIDTH+new_pos.first]) {
                        occupied[new_pos.second*BWIDTH+new_pos.first] = true;
                    }
                    moves[new_pos.second*BWIDTH+new_pos.first] = true;
                }
            }
        }
        minx = INT_MAX;
        miny = INT_MAX;
        maxx = 0;
        maxy = 0;
        new_elves.reset();
        for (int y = 0; y < BHEIGHT; y++) {
            for (int x = 0; x < BWIDTH; x++) {
                if (elves[y*BWIDTH+x]) {
                    auto new_pos = move_to(x, y, round);
                    if (!occupied[new_pos.second*BWIDTH+new_pos.first]) {
                        new_elves[new_pos.second*BWIDTH+new_pos.first] = true;
                        //printf("%d %d -> %d %d\n", x, y, new_pos.first, new_pos.second);
                    } else {
                        new_elves[y*BWIDTH+x] = true;
                        
                    }
                }
            }
        }
        elves = new_elves;
        for (int y = 0; y < BHEIGHT; y++) {
            for (int x = 0; x < BWIDTH; x++) {
                if (elves[y*BWIDTH+x]) {
                    printf("#");
                    minx = min(minx, x);
                    miny = min(miny, y);
                    maxx = max(maxx, x);
                    maxy = max(maxy, y);
                }
                else printf(".");
            }
            printf("\n");
        }
        printf("%d %d %d %d %d\n", (maxx-minx+1)*(maxy-miny+1)-num, minx, miny, maxx, maxy);
    }
}