#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    vector<int> heights;
    int width = 0;
    string line;

    while (getline(cin, line)) {
        width = line.size();
        for (int i = 0; i < width; i++) {
            heights.push_back(line[i] - '0');
        }
    }

    int height = heights.size()/width;

    int num = 0;
    for (int xs = 0; xs < width; xs++) {
        for (int ys = 0; ys < height; ys++) {
            int max = heights[ys*width+xs];
            int l1 = 0;
            for (int y = ys+1; y < height; y++) {
                l1++;
                if (heights[y*width+xs] >= max) {
                    break;
                }
            }

            max = heights[ys*width+xs];
            int l2 = 0;
            for (int y = ys-1; y >= 0; y--) {
                l2++;
                if (heights[y*width+xs] >= max) {
                    break;
                }
            }

            max = heights[ys*width+xs];
            int l3 = 0;
            for (int x = xs+1; x < width; x++) {
                l3++;
                if (heights[ys*width+x] >= max) {
                    break;
                }
            }

            max = heights[ys*width+xs];
            int l4 = 0;
            for (int x = xs-1; x >= 0; x--) {
                l4++;
                if (heights[ys*width+x] >= max) {
                    break;
                }
            }

            int dist = l1*l2*l3*l4;
            if (dist > num) num = dist;
        }
    }

    printf("%d\n", num);
}