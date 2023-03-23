#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

#define SIZE 4000001

bool compare_sensors(pair<pair<int, int>, int> s1, pair<pair<int, int>, int> s2) {
    return s1.first.first < s2.first.first;
}

int main() {
    freopen("input.txt", "r", stdin);

    vector<pair<pair<int, int>, int> > sensors;

    string line;
    while (getline(cin, line)) {
        int pos1 = line.find(',', 0);
        int sx = stoi(line.substr(12, pos1-12));
        int pos2 = line.find(':', 0);
        int sy = stoi(line.substr(pos1+4, pos2-pos1-4));
        int pos3 = line.find(',', pos1+1);
        int bx = stoi(line.substr(pos2+25, pos3-pos2-25));
        int by = stoi(line.substr(pos3+4, line.size()-pos3-4));
        //printf("%d %d %d %d\n", sx, sy, bx, by);
        int dist = abs(sx - bx) + abs(sy - by);
        sensors.push_back(pair<pair<int, int>, int>(pair<int, int>(sx, sy), dist));
    }

    sort(sensors.begin(), sensors.end(), compare_sensors);

    
    for (long y = 0; y < SIZE; y++) {
        long x = 0;
        for (int i = 0; i < sensors.size(); i++) {
            int width = sensors[i].second - abs(sensors[i].first.second - y);
            if (width < 0) continue;
            int start = sensors[i].first.first - width;
            int end = sensors[i].first.first + width;
            if (end < x || start > x) continue;
            x = end+1;
        }
        if (x < SIZE) printf("%ld %ld %ld\n", x, y, x*4000000+y);
    }

    //printf("%d\n", int(cleared.count()-beacons_on_row.size()));
}