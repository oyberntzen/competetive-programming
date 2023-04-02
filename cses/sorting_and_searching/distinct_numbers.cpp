#include <cstdio>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    set<int> seen; 
    int num = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (seen.count(x) == 0) {
            num++;
            seen.insert(x);
        }
    }
    printf("%d\n", num);
}