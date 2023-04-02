#include <cstdio>

int n;
bool code[16];

void flip(int i) {
    if (i >= n) {
        for (int j = 0; j < n; j++) {
            printf("%c", code[j]+'0');
        }
        printf("\n");
        return;
    }
    flip(i+1);
    code[i] = !code[i];
    flip(i+1);
}


int main() {
    scanf("%d", &n);
    flip(0);
}