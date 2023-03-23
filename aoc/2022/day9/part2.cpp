#include <iostream>

#define SIZE 2000
#define START_POS 1000
#define TAILS 10

bool visited[SIZE][SIZE];

int main() {
    freopen("input.txt", "r", stdin);

    int tx[TAILS];
    int ty[TAILS];

    for (int i = 0; i < TAILS; i++) {
        tx[i] = START_POS;
        ty[i] = START_POS;
    }

    char dir[5];
    int length;
    int numVisited = 0;
    int maxX = 0;
    int maxY = 0;
    int minX = 0;
    int minY = 0;
    while (scanf("%s %d\n", dir, &length) != EOF) {
        while (length > 0) {
            if (dir[0] == 'R') {
                tx[0]++;
            } else if (dir[0] == 'U') {
                ty[0]++;
            } else if (dir[0] == 'L') {
                tx[0]--;
            } else if (dir[0] == 'D') {
                ty[0]--;
            }
            for (int i = 1; i < TAILS; i++) {
                if (tx[i-1]-tx[i] == 2) {
                    tx[i]++;
                    if (abs(ty[i-1]-ty[i]) == 1) {
                        ty[i] = ty[i-1];
                    } else if (abs(ty[i-1]-ty[i]) == 2) {
                        ty[i] = (ty[i]+ty[i-1])/2;
                    }
                } else if (ty[i-1]-ty[i] == 2) {
                    ty[i]++;
                    if (abs(tx[i-1]-tx[i]) == 1) {
                        tx[i] = tx[i-1];
                    } else if (abs(tx[i-1]-tx[i]) == 2) {
                        tx[i] = (tx[i]+tx[i-1])/2;
                    }
                } else if (tx[i-1]-tx[i] == -2) {
                    tx[i]--;
                    if (abs(ty[i-1]-ty[i]) == 1) {
                        ty[i] = ty[i-1];
                    } else if (abs(ty[i-1]-ty[i]) == 2) {
                        ty[i] = (ty[i]+ty[i-1])/2;
                    }
                } else if (ty[i-1]-ty[i] == -2) {
                    ty[i]--;
                    if (abs(tx[i-1]-tx[i]) == 1) {
                        tx[i] = tx[i-1];
                    } else if (abs(tx[i-1]-tx[i]) == 2) {
                        tx[i] = (tx[i]+tx[i-1])/2;
                    }
                }
                if (tx[i] > maxX) maxX = tx[i];
                if (tx[i] < minX) minX = tx[i];
                if (ty[i] > maxY) maxY = ty[i];
                if (ty[i] < minY) minY = ty[i];
            }
            if (!visited[tx[9]][ty[9]]) {
                printf("%d %d\n", tx[9], ty[9]);
                visited[tx[9]][ty[9]] = true;
                numVisited++;
            }
            length--;
        }
    }
    printf("%d %d %d %d\n", minX, maxX, minY, maxY);
    printf("%d\n", numVisited);
}