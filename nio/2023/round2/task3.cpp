#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);

    string s;
    getline(cin, s);

    vector<int> letters;
    letters.resize(n);
    for (int i = 0; i < n; i++) {
        letters[i] = s[i]-'A';
    }

    vector<int> before[26];
    for (int i = 0; i < 26; i++) {
        before[i].resize(n);
        int last = -1;
        for (int j = 0; j < n; j++) {
            if (letters[j] == i) last = j;
            before[i][j] = last;
        }
    }

    vector<int> after[26];
    for (int i = 0; i < 26; i++) {
        after[i].resize(n);
        int last = n;
        for (int j = n-1; j >= 0; j--) {
            if (letters[j] == i) last = j;
            after[i][j] = last;
        }
    }

    vector<int> incompatible[26];
    for (int i = 0; i < m; i++) {
        char o, u;
        scanf("%c %c\n", &o, &u);
        incompatible[int(o-'A')].push_back(int(u-'A'));
    }

    vector<int> c;
    c.resize(n);
    for (int i = 0; i < n; i++) c[i] = n+1;
    for (int i = 0; i < n; i++) {
        int a = -1;
        int b = n;
        int x = letters[i];
        for (int j = 0; j < incompatible[x].size(); j++) {
            int y = incompatible[x][j];
            a = max(a, before[y][i]);
            b = min(b, after[y][i]);
        }

        int l = 0;
        if (a != -1) {
            l = n+1;
            for (int j = 0; j < 26; j++) {
                l = min(l, c[after[j][a+1]-1]);
            }
        }
        c[b-1] = min(c[b-1], l+1);
    }
    printf("%d\n", c[n-1]);
}