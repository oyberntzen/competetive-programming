#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int>> moves;
void move(int a, int b, int c, int i) {
    if (i == 0) return;
    move(a, c, b, i-1);
    moves.push_back(make_pair(a, b));
    move(c, b, a, i-1);
}

int main() {
    int n;
    scanf("%d", &n);
    move(1, 3, 2, n);
    printf("%d\n", int(moves.size()));
    for (int i = 0; i < int(moves.size()); i++) {
        printf("%d %d\n", moves[i].first, moves[i].second);
    }
}