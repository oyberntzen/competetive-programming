#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

//#define TEST
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
    int face = 1;

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
                    int last_dir = dir;
                    if (dir == 0) {
                        posx++;
                        if (posx > ranges[posy].second) {
                            #ifdef TEST
                            if (face == 1) {
                                posy = 3-posy+8;
                                posx = 15;
                                dir = 2;
                            } else if (face == 4) {
                                posx = 3-(posy-4)+12;
                                posy = 8;
                                dir = 1;
                            } else if (face == 6) {
                                posy = 3-(posy-8);
                                posx = 11;
                                dir = 2;
                            }
                            #else
                            if (face == 2) {
                                posy = 49-posy+100;
                                posx = 99;
                                dir = 2;
                            } else if (face == 3) {
                                posx = posy-50+100;
                                posy = 49;
                                dir = 3;
                            } else if (face == 5) {
                                posy = 49-(posy-100);
                                posx = 149;
                                dir = 2;
                            } else if (face == 6) {
                                posx = posy-150+50;
                                posy = 149;
                                dir = 3;
                            }
                            #endif
                        }
                    }
                    else if (dir == 1) {
                        posy++;
                        bool valid = true;
                        if (posy >= ranges.size()) valid = false;
                        else if (posx < ranges[posy].first || posx > ranges[posy].second) valid = false;
                        if (!valid) {
                            #ifdef TEST
                            if (face == 2) {
                                posx = 3-posx+8;
                                posy = 11;
                                dir = 3;
                            } else if (face == 3) {
                                posy = 3-(posx-4)+8;
                                posx = 8;
                                dir = 0;
                            } else if (face == 5) {
                                posx = 3-(posx-8);
                                posy = 7;
                                dir = 3;
                            } else if (face == 6) {
                                posy = 3-(posx-12)+4;
                                posx = 0;
                                dir = 0;
                            }
                            #else
                            if (face == 2) {
                                posy = posx-100+50;
                                posx = 99;
                                dir = 2;
                            } else if (face == 5) {
                                posy = posx-50+150;
                                posx = 49;
                                dir = 2;
                            } else if (face == 6) {
                                posx = posx+100;
                                posy = 0;
                                dir = 1;
                            }
                            #endif
                        }
                    }
                    else if (dir == 2) {
                        posx--;
                        if (posx < ranges[posy].first) {
                            #ifdef TEST
                            if (face == 1) {
                                posx = posy;
                                posy = 4;
                                dir = 1;
                            } else if (face == 2) {
                                posx = 3-(posy-4)+12;
                                posy = 11;
                                dir = 3;
                            } else if (face == 5) {
                                posx = 3-(posy-8)+4;
                                posy = 7;
                                dir = 3;
                            }
                            #else
                            if (face == 1) {
                                posy = 49-posy+100;
                                posx = 0;
                                dir = 0;
                            } else if (face == 3) {
                                posx = posy-50;
                                posy = 100;
                                dir = 1;
                            } else if (face == 4) {
                                posy = 49-(posy-100);
                                posx = 50;
                                dir = 0;
                            } else if (face == 6) {
                                posx = posy-150+50;
                                posy = 0;
                                dir = 1;
                            }
                            #endif
                        }
                    }
                    else if (dir == 3) {
                        posy--;
                        bool valid = true;
                        if (posy < 0) valid = false;
                        else if (posx < ranges[posy].first || posx > ranges[posy].second) valid = false;
                        if (!valid) {
                            #ifdef TEST
                            if (face == 2) {
                                posx = 3-posx+8;
                                posy = 0;
                                dir = 1;
                            } else if (face == 3) {
                                posy = posx-4;
                                posx = 8;
                                dir = 0;
                            } else if (face == 1) {
                                posx = 3-(posx-8);
                                posy = 4;
                                dir = 1;
                            } else if (face == 6) {
                                posy = 3-(posx-12)+4;
                                posx = 11;
                                dir = 2;
                            }
                            #else
                            if (face == 1) {
                                posy = posx-50+150;
                                posx = 0;
                                dir = 0;
                            } else if (face == 2) {
                                posx = posx-100;
                                posy = 199;
                                dir = 3;
                            } else if (face == 4) {
                                posy = posx+50;
                                posx = 50;
                                dir = 0;
                            }
                            #endif
                        }
                    }
                    if (walls[posy*WIDTH+posx]) {
                        posx = last_posx;
                        posy = last_posy;
                        dir = last_dir;
                        break;
                    }

                    #ifdef TEST
                    if (posy < 4) face = 1;
                    else if (posy < 8) face = posx/4+2;
                    else face = (posx-8)/4+5;
                    #else
                    if (posy < 50) face = (posx-50)/50 + 1;
                    else if (posy < 100) face = 3;
                    else if (posy < 150) face = posx/50 + 4;
                    else face = 6;
                    #endif
                    //printf("%d %d %d %d\n", posx, posy, dir, face);
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