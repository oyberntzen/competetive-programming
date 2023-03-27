#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if ((a+b)%3 == 0 && min(a, b)*2 >= max(a, b)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}