#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("gaver.txt", "r", stdin);

    string line;
    vector<bool> containsAlv;
    while (getline(cin, line)) {
        if (line.find("alv") != string::npos) {
            containsAlv.push_back(true);
        } else {
            containsAlv.push_back(false);
        }
    }

    int lines = 0;
    int things = 0;
    for (int i = 0; i < containsAlv.size(); i++) {
        if (i > 0) {
            if (containsAlv[i-1]) {
                things--;
            }
        }
        
        things += 1;
        lines += max(things-2, 1) + 1;
        cout << lines << endl;
    }
}