#include <iostream>
#include <string>

using namespace std;

int num[26];
string permutation;
int n;
bool print = false;
int m = 0;
void search() {
    if (permutation.size() == n) {
        if (print) printf("%s\n", permutation.c_str());
        m++;
    } else {
        for (int i = 0; i < 26; i++) {
            if (num[i] > 0) {
                permutation.push_back('a'+i);
                num[i]--;
                search();
                permutation.pop_back();
                num[i]++;
            }
        }
    }
}

int main() {
    string inp;
    getline(cin, inp);
    n = inp.size();
    for (int i = 0; i < n; i++) {
        num[inp[i]-'a']++;
    }
    search();
    printf("%d\n", m);
    print = true;
    search();
}