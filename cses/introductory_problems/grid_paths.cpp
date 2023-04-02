#include <iostream>
#include <string>
using namespace std;

#define N 7

bool visited[N+2][N+2];
int num = 0;
string s;
void solve(int i, int x, int y) {
    if (x == 1 && y == N) {
        //printf("%d %d %d\n", i, x, y);
        if (i == 48) num++;
        return;
    }
    if (i == 48) return;

    if (visited[x-1][y] == visited[x+1][y] && visited[x][y-1] == visited[x][y+1] && visited[x-1][y] != visited[x][y-1]) return;

    visited[x][y] = true;

    if (!visited[x-1][y] && (s[i] == '?' || s[i] == 'L')) {
        solve(i+1, x-1, y);
    }
    if (!visited[x+1][y] && (s[i] == '?' || s[i] == 'R')) {
        solve(i+1, x+1, y);
    }
    if (!visited[x][y-1] && (s[i] == '?' || s[i] == 'U')) {
        solve(i+1, x, y-1);
    }
    if (!visited[x][y+1] && (s[i] == '?' || s[i] == 'D')) {
        solve(i+1, x, y+1);
    }
    visited[x][y] = false;
}

int main() {
    for (int i = 0; i < N+1; i++) {
        visited[i][0] = true;
        visited[i][N+1] = true;
        visited[0][i] = true;
        visited[N+1][i] = true;
    }
    getline(cin, s);
    solve(0, 1, 1);
    printf("%d\n", num);
}