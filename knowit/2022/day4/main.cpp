#include <stdio.h>

int num[25];
int len;

void to_base(int value, int base) {
    int i = 0;
    for (;value != 0; i++) {
        num[i] = value % base;
        value /= base;
    }
    len = i;
}

bool palindrome() {
    for (int i = 0; i < (len+1)/2; i++) {
        if (num[i] != num[len-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int multiPalindromes = 0;
    for (int i = 0; i < n; i++) {
        int palindromes = 0;
        for (int base = 2; base <= 16; base++) {
            to_base(i, base);
            if (palindrome()) palindromes++;
        }
        
        if (palindromes >= 3) multiPalindromes += i;
    }
    printf("%d\n", multiPalindromes);
}