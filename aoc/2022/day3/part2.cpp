#include <iostream>
#include <string>

using namespace std;

#define GROUP_SIZE 3

struct rucksack {
    bool upperCaseUsed[26];
    bool lowerCaseUsed[26];
};

rucksack rucksackFromItems(const string& items) {
    rucksack rsack;
    for (int i = 0; i < 26; i++) {
        rsack.upperCaseUsed[i] = false;
        rsack.lowerCaseUsed[i] = false;
    }

    for (int i = 0; i < items.size(); i++) {
        if (items[i] >= 'A' && items[i] <= 'Z') {
            rsack.upperCaseUsed[items[i]-'A'] = true;
        } else {
            rsack.lowerCaseUsed[items[i]-'a'] = true;
        }
    }
    return rsack;
}

int main() {
    freopen("input.txt", "r", stdin);

    rucksack rucksacks[GROUP_SIZE];
    string items[GROUP_SIZE];
    int sumPriorities = 0;
    while (getline(cin, items[0])) {
        for (int i = 1; i < GROUP_SIZE; i++) {
            getline(cin, items[i]);
        }

        for (int i = 0; i < GROUP_SIZE; i++) {
            rucksacks[i] = rucksackFromItems(items[i]);
        }

        for (int i = 0; i <= 26; i++) {
            bool hasItem = true;
            for (int j = 0; j < GROUP_SIZE; j++) {
                if (!rucksacks[j].upperCaseUsed[i]) {
                    hasItem = false;
                    break;
                }
            }
            if (hasItem) {
                sumPriorities += i+27;
                break;
            }
        }

        for (int i = 0; i <= 26; i++) {
            bool hasItem = true;
            for (int j = 0; j < GROUP_SIZE; j++) {
                if (!rucksacks[j].lowerCaseUsed[i]) {
                    hasItem = false;
                    break;
                }
            }
            if (hasItem) {
                sumPriorities += i+1;
                break;
            }
        }
    }
    cout << sumPriorities << endl;
}