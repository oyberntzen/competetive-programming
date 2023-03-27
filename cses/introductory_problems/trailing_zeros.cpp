#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int twos = 0;
int fives = 0;

int main() {
    int n;
    scanf("%d", &n);

    int exp = 2;
    int twos = 0;
    while (exp <= n) {
        twos += n/exp;
        exp *= 2;
    }

    exp = 5;
    int fives = 0;
    while (exp <= n) {
        fives += n/exp;
        exp *= 5;
    }

    printf("%d\n", min(twos, fives));
}