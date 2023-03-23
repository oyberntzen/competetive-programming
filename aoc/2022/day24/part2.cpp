#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define WIDTH 122
#define HEIGHT 27

bitset<WIDTH*HEIGHT> walls;
bitset<WIDTH*HEIGHT> ups;
bitset<WIDTH*HEIGHT> downs;
bitset<WIDTH*HEIGHT> lefts;
bitset<WIDTH*HEIGHT> rights;
bitset<WIDTH*HEIGHT> you;

int main() {
    freopen("input.txt", "r", stdin);
    for (int y = 0; y < HEIGHT; y++) {
        string line;
        getline(cin, line);
        for (int x = 0; x < WIDTH; x++) {
            switch (line[x])
            {
            case '#':
                walls[y*WIDTH+x] = true;
                break;
            case '^':
                ups[y*WIDTH+x] = true;
                break;
            case 'v':
                downs[y*WIDTH+x] = true;
                break;
            case '<':
                lefts[y*WIDTH+x] = true;
                break;
            case '>':
                rights[y*WIDTH+x] = true;
                break;
            default:
                break;
            }
        }
    }
    you[1] = true;
    int state = 0;
    for (int i = 0; true; i++) {
        you |= (you << 1) | (you >> 1) | (you << WIDTH) | (you >> WIDTH);

        ups = ups >> WIDTH;
        ups |= (ups&walls) << (WIDTH*(HEIGHT-2));
        ups &= ~walls;

        downs = downs << WIDTH;
        downs |= (downs&walls) >> (WIDTH*(HEIGHT-2));
        downs &= ~walls;

        lefts = lefts >> 1;
        lefts |= (lefts&walls) << (WIDTH-2);
        lefts &= ~walls;

        rights = rights << 1;
        rights |= (rights&walls) >> (WIDTH-2);
        rights &= ~walls;

        you &= ~walls;
        you &= ~ups;
        you &= ~downs;
        you &= ~lefts;
        you &= ~rights;

        if (you[HEIGHT*WIDTH-2] && state == 0) {
            printf("%d\n", i+1);
            state = 1;
            you.reset();
            you[HEIGHT*WIDTH-2] = true;
        }

        if (you[1] && state == 1) {
            printf("%d\n", i+1);
            state = 2;
            you.reset();
            you[1] = true;
        }

        if (you[HEIGHT*WIDTH-2] && state == 2) {
            printf("%d\n", i+1);
            break;
        }
    }
}