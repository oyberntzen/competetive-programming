#include <iostream>

#define N 4

int parity_bits[N] = {1, 2, 4, 8};

int bits[N*N] = {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0};
bool correct[N*N];

int main() {
    for (int i = 0; i < N; i++) {
        int num = 0;
        int j = 0;
        int sum = 0;
        while (j < N*N) {
            if (num == 0) {
                j += parity_bits[i];
                num = parity_bits[i];
            }
            sum += bits[j];
            j++;
            num--;
        }
        if (sum%2 == 0) {
            num = 0;
            j = 0;
            while (j < N*N) {
                if (num == 0) {
                    j += parity_bits[i];
                    num = parity_bits[i];
                }
                correct[j] = true;
                printf("%d ", j);
                j++;
                num--;
            }
        } else {
            num = parity_bits[i];
            j = 0;
            while (j < N*N) {
                if (num == 0) {
                    j += parity_bits[i];
                    num = parity_bits[i];
                }
                if (j >= N*N) break;
                correct[j] = true;
                printf("%d ", j);
                j++;
                num--;
            }
        }
        printf("\n");
    }

    int j = 0;
    for (int i = 1; i < N*N; i++) {
        if (j < N && parity_bits[j] == i) {
            j++;
        } else {
            if (!correct[i]) bits[i] = !bits[i];
            printf("%d", bits[i]);
        }
    }

    printf("\n");
}

// 100000101100110101111000101110111