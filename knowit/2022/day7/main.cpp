#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    freopen("encrypted.txt", "r", stdin);

    string line;
    bitset<32> bits;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i += 7) {
            bits = bitset<32>(stoi(line.substr(i, 6)));
            if (bits.count() % 2 == 0) {
                printf("  ");
            } else {
                printf("00");
            }
        }
        printf("\n");
    }
}