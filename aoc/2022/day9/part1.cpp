#include <iostream>

#define SIZE 1000
#define START_POS 500

bool visited[SIZE][SIZE];

int main() {
    freopen("input.txt", "r", stdin);

    int hx = START_POS;
    int hy = START_POS;
    int tx = START_POS;
    int ty = START_POS;

    char dir[2];
    int length;
    int numVisited = 0;
    while (scanf("%s %d\n", dir, &length) != EOF) {
        while (length > 0) {
            if (dir[0] == 'R') {
                hx++;
                if (hx-tx == 2) {
                    tx++;
                    ty = hy;
                }
            } else if (dir[0] == 'U') {
                hy++;
                if (hy-ty == 2) {
                    ty++;
                    tx = hx;
                }
            } else if (dir[0] == 'L') {
                hx--;
                if (hx-tx == -2) {
                    tx--;
                    ty = hy;
                }
            } else if (dir[0] == 'D') {
                hy--;
                if (hy-ty == -2) {
                    ty--;
                    tx = hx;
                }
            }
            if (!visited[tx][ty]) {
                visited[tx][ty] = true;
                numVisited++;
            }
            length--;
        }
    }

    printf("%d\n", numVisited);
}