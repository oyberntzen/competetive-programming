#include <iostream>
#include <bitset>

using namespace std;

#define SIZE 25

bitset<SIZE*SIZE*SIZE> filled(0);

bool check(int x, int y, int z) {
    return filled[x*SIZE*SIZE+y*SIZE+z];
}

int main() {
    freopen("input.txt", "r", stdin);
    int x, y, z;
    int area = 0;
    while (scanf("%d,%d,%d", &x, &y, &z) != EOF) {
        filled[x*SIZE*SIZE+y*SIZE+z] = true;
        area += 6;
        if (check(x+1,y,z)) area -= 2;
        if (check(x-1,y,z)) area -= 2;
        if (check(x,y+1,z)) area -= 2;
        if (check(x,y-1,z)) area -= 2;
        if (check(x,y,z+1)) area -= 2;
        if (check(x,y,z-1)) area -= 2;
    }
    printf("%d\n", area);
}