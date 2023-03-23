#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#define HEIGHT 100000000
#define WIDTH 7

vector<vector<pair<int, int> > > pieces = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
};

bitset<WIDTH*HEIGHT> filled(0);
int current_piece = 0;
int x = 2;
int y = 3;
int max_height = 0;

bool collide() {
    for (int i = 0; i < pieces[current_piece].size(); i++) {
        int sx = x+pieces[current_piece][i].first;
        int sy = y+pieces[current_piece][i].second;
        if (sx < 0 || sx >= WIDTH) return true;
        if (sy < 0) return true;
        if (sy >= HEIGHT) printf("%d\n", sy);
        if (filled[sy*WIDTH+sx]) return true;
    }
    return false;
}

void pprint() {
    for (int sy = max_height-1; sy >= 0; sy--) {
        for (int sx = 0; sx < WIDTH; sx++) {
            if (filled[sy*WIDTH+sx]) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    string movements;
    getline(cin, movements);

    int num = 0;
    int i = 0;
    while (num < 2022) {
        int deltax = 1;
        if (movements[i] == '<') deltax = -1;
        x += deltax;
        if (collide()) x -= deltax;
        i = (i+1)%movements.size();

        y--;
        if (collide()) {
            y++;
            for (int i = 0; i < pieces[current_piece].size(); i++) {
                int sx = x+pieces[current_piece][i].first;
                int sy = y+pieces[current_piece][i].second;
                filled[sy*WIDTH+sx] = true;
                if (sy >= max_height) max_height = sy+1;
            }
            //pprint();
            current_piece = (current_piece + 1) % pieces.size();
            num++;
            x = 2;
            y = max_height+3;
        }
    }
    printf("%d\n", max_height);
}