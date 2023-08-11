#include <vector>
#include "glolib.h"
using namespace std;

vector<int> p;
vector<vector<int>> c;
vector<int> state;
vector<int> leaves;

void update_state(int a, int k) {
    state[a] = k;
    while (a != 0) {
        //printf("%d %d %d\n", a+1, state[a], k);
        a = p[a];
        state[a] += k;
        if (state[a] < 0) k = -1;
        else if (state[a] == 0) k = 0;
        else k = 1;
    }
}

void rand_move() {
    for (int i = 0; i < int(leaves.size()); i++) {
        if (state[leaves[i]] == 0) {
            update_state(leaves[i], 1);
            int m = ruch(leaves[i] + 1)-1;
            update_state(m, -1);
            break;
        }
    }
}

void calc_move(int a) {
    //printf("%d: %d\n", a+1, state[a]);
    if (c[a].size() == 0) {
        update_state(a, 1);
        int m = ruch(a + 1)-1;
        update_state(m, -1);
        return;
    }
    for (int b : c[a]) {
        if (state[b] == 0) {
            calc_move(b);
            return;
        }
    }
    rand_move();
}

int main() {
    int n = daj_n();
    p.resize(n);
    c.resize(n);
    state.resize(n);
    
    for(int i = 2; i <= n; i++) {
        int parent = daj_przelozonego(i)-1;
        p[i-1] = parent;
        c[parent].push_back(i-1);
    }

    for (int i = 0; i < n; i++) {
        if (c[i].size() == 0) {
            leaves.push_back(i);
        }
    }

    int x = 0;
    while (x < int(leaves.size())) {
        //printf("%d %d\n", x, int(leaves.size()));
        calc_move(0);
        x += 2;
    }
}
