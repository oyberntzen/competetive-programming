#include <iostream>
#include <bitset>

using namespace std;

#define SIZE 25

bitset<SIZE*SIZE*SIZE> filled(0);
bitset<SIZE*SIZE*SIZE> visited(0);
int area = 0;

void search(int x, int y, int z) {
    if (filled[x*SIZE*SIZE+y*SIZE+z]) {
        area++;
        return;
    }
    if (visited[x*SIZE*SIZE+y*SIZE+z]) return;
    visited[x*SIZE*SIZE+y*SIZE+z] = true;
    if (x > 0) {
        search(x-1, y, z);
    }
    if (x < SIZE-1) {
        search(x+1, y, z);
    }
    if (y > 0) {
        search(x, y-1, z);
    }
    if (y < SIZE-1) {
        search(x, y+1, z);
    }
    if (z > 0) {
        search(x, y, z-1);
    }
    if (z < SIZE-1) {
        search(x, y, z+1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int x, y, z;
    while (scanf("%d,%d,%d", &x, &y, &z) != EOF) {
        x++;
        y++;
        z++;
        filled[x*SIZE*SIZE+y*SIZE+z] = true;
    }
    search(0, 0, 0);
    printf("%d\n", area);
}