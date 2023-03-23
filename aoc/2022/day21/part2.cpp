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
    string root;
    while (getline(cin, line)) {
        if (line.substr(0, 4) == "root") {
            root = line;
            continue;
        }
        if (line.substr(0, 4) == "humn") continue;
        if (line.size() == 17) {
            lines.push_back(line);
            continue;
        }
        nums[line.substr(0, 4)] = stoi(line.substr(6, line.size()-6));
    }

    int i = 0;
    bool finished = true;
    while (lines.size() > 0) {
        if (nums.find(lines[i].substr(6, 4)) == nums.end() || nums.find(lines[i].substr(13, 4)) == nums.end()) {
            i++;
            if (i >= lines.size()) {
                i = 0;
                if (finished) break;
                finished = true;
            }
            continue;
        }
        finished = false;
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
        if (i >= lines.size()) {
            i = 0;
            finished = true;
        }
    }

    if (nums.find(root.substr(6, 4)) == nums.end()) {
        nums[root.substr(6, 4)] = nums[root.substr(13, 4)];
    } else {
        nums[root.substr(13, 4)] = nums[root.substr(6, 4)];
    }

    i = 0;
    while (nums.find("humn") == nums.end()) {
        if (nums.find(lines[i].substr(0, 4)) == nums.end()) {
            i = (i+1)%lines.size();
            continue;
        }
        if (nums.find(lines[i].substr(6, 4)) == nums.end() && nums.find(lines[i].substr(13, 4)) == nums.end()) {
            i = (i+1)%lines.size();
            continue;
        }
        ll num1 = nums[lines[i].substr(0, 4)];
        ll num2;
        string name;
        bool first = false;
        if (nums.find(lines[i].substr(6, 4)) == nums.end()) {
            name = lines[i].substr(6, 4);
            num2 = nums[lines[i].substr(13, 4)];
        } else {
            name = lines[i].substr(13, 4);
            num2 = nums[lines[i].substr(6, 4)];
            first = true;
        }
        //printf("%lld %lld %s\n", num1, num2, name.c_str());
        char op = lines[i][11];
        if (op == '+') {
            nums[name] = num1-num2;
        } else if (op == '-') {
            nums[name] = first ? num2-num1 : num1+num2;
        } else if (op == '*') {
            nums[name] = num1/num2;
        } else if (op == '/') {
            nums[name] = first ? num2/num1 : num1*num2;
        }
        //printf("%lld\n", nums[name]);
        lines.erase(lines.begin()+i);
        if (i >= lines.size()) i = 0;
    }

    printf("%lld\n", nums["humn"]);
}