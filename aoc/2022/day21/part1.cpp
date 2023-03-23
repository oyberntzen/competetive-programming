#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);

    string line;
    vector<string> lines;
    map<string, ll> nums;
    while (getline(cin, line)) {
        if (line.size() == 17) {
            lines.push_back(line);
            continue;
        }
        nums[line.substr(0, 4)] = stoi(line.substr(6, line.size()-6));
    }

    int i = 0;
    while (lines.size() > 0) {
        if (nums.find(lines[i].substr(6, 4)) == nums.end()) {
            i = (i+1)%lines.size();
            continue;
        }
        if (nums.find(lines[i].substr(13, 4)) == nums.end()) {
            i = (i+1)%lines.size();
            continue;
        }
        ll num1 = nums[lines[i].substr(6, 4)];
        ll num2 = nums[lines[i].substr(13, 4)];
        char op = lines[i][11];
        if (op == '+') {
            nums[lines[i].substr(0, 4)] = num1+num2;
        } else if (op == '-') {
            nums[lines[i].substr(0, 4)] = num1-num2;
        } else if (op == '*') {
            nums[lines[i].substr(0, 4)] = num1*num2;
        } else if (op == '/') {
            nums[lines[i].substr(0, 4)] = num1/num2;
        }
        lines.erase(lines.begin()+i);
        if (i >= lines.size()) i = 0;
    }

    printf("%lld\n", nums["root"]);
}