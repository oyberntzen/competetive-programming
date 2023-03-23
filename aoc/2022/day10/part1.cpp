#include <iostream>

int main() {
    freopen("input.txt", "r", stdin);

    char op[5];
    int num;
    int cycle = 0;
    int x = 1;
    int tot = 0;
    int last_num = 0;
    while (scanf("%s %d", op, &num) != EOF) {
        if ((cycle+20)%40 == 0) {
            tot += cycle*x - last_num*cycle;
            printf("N %d %d %d\n", cycle, x, cycle*x);
        }
        //printf("%d %s\n", num, op);

        last_num = 0;
        if (op[0] == 'n') {
            cycle++;
        } else {
            cycle++;
            if ((cycle+20)%40 == 0) {
                tot += cycle*x;
                printf("A %d %d %d\n", cycle, x, cycle*x);
            }
            cycle++;
            x += num;
            last_num = num;
        }
    }
    printf("%d\n", tot);
}