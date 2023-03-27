#include <iostream>
#include <string>

using namespace std;

int letter[26];

int main() {
    string inp;
    getline(cin, inp);
    for (int i = 0; i < inp.size(); i++) {
        letter[inp[i]-'A']++;
    }
    int odd = -1;
    for (int i = 0; i < 26; i++) {
        if (letter[i]%2 != 0) {
            if (odd == -1) odd = i;
            else {
                printf("NO SOLUTION\n");
                return 0;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (i == odd) continue;
        for (int j = 0; j < letter[i]/2; j++) printf("%c", 'A'+i);
    }
    for (int j = 0; j < letter[odd]; j++) printf("%c", 'A'+odd);
    for (int i = 25; i >= 0; i--) {
        if (i == odd) continue;
        for (int j = 0; j < letter[i]/2; j++) printf("%c", 'A'+i);
    }
    printf("\n");
}