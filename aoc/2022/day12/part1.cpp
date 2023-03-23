#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > heightmap;
vector<vector<int> > dist;

void s(int x, int y, int d, char h) {
    if (x < 0 || x >= heightmap[0].size()) return;
    if (y < 0 || y >= heightmap.size()) return;
    if (heightmap[y][x] == 'S') {
        dist[y][x] = d + 1;
        return;
    }
    if (abs(int(h) - int(heightmap[y][x])) > 1) return;

    d++;
    printf("%d %d %d\n", x, y, d);
    if (dist[y][x] > d) {
        dist[y][x] = d;
        s(x-1, y, d, heightmap[y][x]);
        s(x+1, y, d, heightmap[y][x]);
        s(x, y-1, d, heightmap[y][x]);
        s(x, y+1, d, heightmap[y][x]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
   
    string line;

    int ex, ey;
    int sx, sy;
    for (int i = 0; getline(cin, line); i++) {
        heightmap.push_back(vector<char>());
        dist.push_back(vector<int>());
        for (int j = 0; j < line.size(); j++) {
            heightmap[i].push_back(line[j]);
            dist[i].push_back(INT32_MAX);
            if (line[j] == 'E') {
                ex = j;
                ey = i;
            } else if (line[j] == 'S') {
                sx = j;
                sy = i;
            }
        }
    }

    heightmap[ey][ex] = 'z';
    heightmap[sy][sx] = 'a';
    dist[ey][ex] = 0;

    for (int i = 0; i < 1000; i++) {
        for (int y = 0; y < dist.size(); y++) {
            for (int x = 0; x < dist[y].size(); x++) {
                if (dist[y][x] != INT32_MAX) {
                    if (y > 0) {
                        if (heightmap[y][x]-heightmap[y-1][x] <= 1 && dist[y-1][x] > dist[y][x]+1) {
                            dist[y-1][x] = dist[y][x]+1;
                        }
                    }
                    if (y < heightmap.size()-1) {
                        if (heightmap[y][x]-heightmap[y+1][x] <= 1 && dist[y+1][x] > dist[y][x]+1) {
                            dist[y+1][x] = dist[y][x]+1;
                        }
                    }
                    if (x > 0) {
                        if (heightmap[y][x]-heightmap[y][x-1] <= 1 && dist[y][x-1] > dist[y][x]+1) {
                            dist[y][x-1] = dist[y][x]+1;
                        }
                    }
                    if (x < heightmap[y].size()-1) {
                        if (heightmap[y][x]-heightmap[y][x+1] <= 1 && dist[y][x+1] > dist[y][x]+1) {
                            dist[y][x+1] = dist[y][x]+1;
                        }
                    }
                }
            }
        }
    }
    
    int record = INT32_MAX;
    for (int y = 0; y < dist.size(); y++) {
        for (int x = 0; x < dist[y].size(); x++) {
            if (heightmap[y][x] == 'a' && dist[y][x] < record) record = dist[y][x];
        }
    }

    

    printf("%d %d\n", dist[sy][sx], record);
}