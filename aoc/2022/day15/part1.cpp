#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define MINX -1000000
#define MAXX 6000000
#define Y 2000000

int main() {
    freopen("input.txt", "r", stdin);

    vector<pair<int, int> > sensors;
    vector<pair<int, int> > beacons;

    string line;
    vector<int> beacons_on_row;
    while (getline(cin, line)) {
        int pos1 = line.find(',', 0);
        int sx = stoi(line.substr(12, pos1-12));
        int pos2 = line.find(':', 0);
        int sy = stoi(line.substr(pos1+4, pos2-pos1-4));
        int pos3 = line.find(',', pos1+1);
        int bx = stoi(line.substr(pos2+25, pos3-pos2-25));
        int by = stoi(line.substr(pos3+4, line.size()-pos3-4));
        //printf("%d %d %d %d\n", sx, sy, bx, by);
        sensors.push_back(pair<int, int>(sx, sy));
        beacons.push_back(pair<int, int>(bx, by));
        if (by == Y) {
            bool add = true;
            for (int i = 0; i < beacons_on_row.size(); i++) {
                if (beacons_on_row[i] == bx) {
                    add = false;
                    break;
                }
            }
            if (add) beacons_on_row.push_back(bx);
        }
    }

    bitset<MAXX-MINX> cleared(0);
    for (int i = 0; i < sensors.size(); i++) {
        int dist = abs(sensors[i].first - beacons[i].first) + abs(sensors[i].second - beacons[i].second);
        int width = dist - abs(sensors[i].second - Y);
        //printf("%d %d %d\n", width, abs(sensors[i].second - Y), dist);
        if (width >= 0) {
            for (int x = sensors[i].first-width; x <= sensors[i].first+width; x++) {
                //printf("%d\n", x);
                if (x < MINX || x >= MAXX) printf("%d\n", x-MINX);
                cleared.set(x-MINX);
                
            }
        }
    }

    printf("%d\n", int(cleared.count()-beacons_on_row.size()));
}