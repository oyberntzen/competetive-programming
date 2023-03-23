#include <iostream>

int main() {
    freopen("input.txt", "r", stdin);

    char op[5];
    int num;
    int cycle = 1;
    int x = 1;
    int last_num = 0;
    int cycles_left = 0;
    while (scanf("%s %d", op, &num) != EOF) {
        if (op[0] == 'n') {
            cycles_left = 0;
        } else {
            cycles_left = 1;
        }
        while (true) {
            if ((cycle-1)%40 == 0) {
                printf("\n");
            }
            int pixel = (cycle-1)%40;
            if (abs(pixel-x) < 2) {
                printf("#");
            } else {
                printf(".");
            }

            cycle++;
            if (cycles_left == 0) {
                if (op[0] == 'a') {
                    x += num;
                }
                break;
            }
            
            cycles_left--;
        }
    }
    printf("\n");
}