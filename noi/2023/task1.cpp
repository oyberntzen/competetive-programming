#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, map<string, int>> scores;
vector<string> current;
void dfs() {

}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    vector<string> training(n);
    for (int i = 0; i < n; i++) {
        cin >> training[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;

        vector<string> words(k);
        for (int j = 0; j < k; j++) {
            cin >> words[j];
        }

        map<string, int> u;
        int record = 0;
        string record_word;
        for (int i = 0; i < n-1; i++) {
            if (training[i] == words[0]) {
                if (u.count(training[i+1]) == 0) u[training[i+1]] = 0;
                u[training[i+1]] += 1;
                if (u[training[i+1]] > record) {
                    record = u[training[i+1]];
                    record_word = training[i+1];
                }
            }
        }
        if (record > 0) cout << record_word << endl;
        else cout << words[0] << endl;
    }
}