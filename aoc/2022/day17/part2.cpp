#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <set>

using namespace std;

#define HEIGHT 100000000
#define WIDTH 7
#define SAVED 7
#define ROCKS 1000000000000

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

typedef pair<pair<pair<int, int>, int>, bitset<WIDTH*SAVED> > pos;

int main() {
    freopen("input.txt", "r", stdin);
    string movements;
    getline(cin, movements);

    vector<pos> saves;

    int num = 0;
    int i = 0;
    bool found = false;
    pos found_pos;
    int found_num;
    int found_num2;
    int found_height;
    int found_height2;
    while (true) {
        int deltax = 1;
        if (movements[i] == '<') deltax = -1;
        x += deltax;
        if (collide()) x -= deltax;

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

        i++;
        if (i == movements.size()) {
            bitset<SAVED*WIDTH> last_filled(0);
            for (int j = 0; j < SAVED*WIDTH; j++) {
                last_filled[j] = filled[(max_height-SAVED)*WIDTH+j];
            }
            pos p = {{{x, max_height-y}, current_piece}, last_filled};
            if (!found) {
                //printf("%lu\n", saves.size());
                for (int j = 0; j < saves.size(); j++) {
                    if (saves[j].first != p.first) continue;
                    if (saves[j].second != p.second) continue;
                    found = true;
                    found_pos = p;
                    found_num = num;
                    found_height = max_height;
                    break;
                }
                if (!found) {
                    saves.push_back(p);
                }
            } else {
                if (p == found_pos) {
                    found_num2 = num;
                    found_height2 = max_height;
                    break;
                }
            }
            i = 0;
        }
    }

    long rocks_left = ROCKS;
    rocks_left -= found_num2;
    long height = (rocks_left/(long)(found_num2-found_num))*(long)(found_height2-found_height);
    rocks_left -= (rocks_left/(long)(found_num2-found_num))*(long)(found_num2-found_num);

    while (rocks_left > 0) {
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
            rocks_left--;
            x = 2;
            y = max_height+3;
        }
    }

    printf("%ld %ld\n", rocks_left, height+(long)max_height);
}