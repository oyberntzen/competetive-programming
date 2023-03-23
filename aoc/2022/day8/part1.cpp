#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    vector<int> heights;
    int width = 0;
    string line;
    vector<bool> visible;

    while (getline(cin, line)) {
        width = line.size();
        for (int i = 0; i < width; i++) {
            heights.push_back(line[i] - '0');
            visible.push_back(false);
        }
    }

    int height = heights.size()/width;

    for (int x = 0; x < width; x++) {
        int max = -1;
        for (int y = 0; y < height; y++) {
            if (heights[y*width+x] > max) {
                visible[y*width+x] = true;
                max = heights[y*width+x];
            }
        }
    }

    for (int x = 0; x < width; x++) {
        int max = -1;
        for (int y = height-1; y >= 0; y--) {
            if (heights[y*width+x] > max) {
                visible[y*width+x] = true;
                max = heights[y*width+x];
            }
        }
    }

    for (int y = 0; y < height; y++) {
        int max = -1;
        for (int x = 0; x < width; x++) {
            if (heights[y*width+x] > max) {
                visible[y*width+x] = true;
                max = heights[y*width+x];
            }
        }
    }

    for (int y = 0; y < height; y++) {
        int max = -1;
        for (int x = width-1; x >= 0; x--) {
            if (heights[y*width+x] > max) {
                visible[y*width+x] = true;
                max = heights[y*width+x];
            }
        }
    }

    int num = 0;
    for (int i = 0; i < visible.size(); i++) {

        if (visible[i]) num++;
    }

    printf("%d\n", num);
}