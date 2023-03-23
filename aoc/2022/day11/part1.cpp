#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<queue<int> > starting_items;
vector<bool> operations;
vector<int> operation_nums;
vector<int> test_num;
vector<int> test_true;
vector<int> test_false;
vector<int> inspects;

int main() {
    freopen("input.txt", "r", stdin);

    string line;
    int monkey = 0;
    while (getline(cin, line)) {
        getline(cin, line);
        int i = 18;
        int last = 16;
        starting_items.push_back(queue<int>());
        for (; i < line.size(); i++) {
            if (line[i] == ',') {
                starting_items[monkey].push(stoi(line.substr(last+2, i-last-2)));
                last = i;
            }
        }
        starting_items[monkey].push(stoi(line.substr(last+2, i-last-2)));
        
        getline(cin, line);
        if (line[23] == '+') {
            operations.push_back(false);
        } else {
            operations.push_back(true);
        }
        if (line[25] == 'o') {
            operation_nums.push_back(-1);
        } else {
            operation_nums.push_back(stoi(line.substr(25, line.size()-25)));
        }
        
        getline(cin, line);
        test_num.push_back(stoi(line.substr(21, line.size()-21)));
        
        getline(cin, line);
        test_true.push_back(stoi(line.substr(29, line.size()-29)));
        
        getline(cin, line);
        test_false.push_back(stoi(line.substr(30, line.size()-30)));

        inspects.push_back(0);
        
        if (!getline(cin, line)) break;
        monkey++;
    }
    
    for (int round = 0; round < 20; round++) {
        for (int i = 0; i < starting_items.size(); i++) {
            while (starting_items[i].size() > 0) {
                int item = starting_items[i].front();
                printf("%d %d\n", i, item);
                starting_items[i].pop();

                int factor = operation_nums[i];
                if (factor == -1) factor = item;

                if (!operations[i]) {
                    item += factor;
                } else {
                    item *= factor;
                }
                item /= 3;
                printf("%d\n", factor);
                inspects[i]++;

                if (item % test_num[i] == 0) {
                    starting_items[test_true[i]].push(item);
                } else {
                    starting_items[test_false[i]].push(item);
                }
            }
        }
    }

    sort(inspects.begin(), inspects.end());

    printf("%d\n", inspects[inspects.size()-1]*inspects[inspects.size()-2]);
    
}