#include <iostream>
#include <string>
#include <vector>

using namespace std;
string line;
vector<int> sizes;

pair<int, bool> search_dir() {
    getline(cin, line);
    int size = 0;
    int search = false;
    while (getline(cin, line)) {
        if (line[0] == '$') {
            search = true;
            break;
        }
        if (line.substr(0, 3) == "dir") {
            continue;
        }
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                size += atoi(line.substr(0, i).c_str());
            }
        }
    }
    if (!search) {
        sizes.push_back(size);
        return pair<int, bool>(size, true);
    }

    do {
        if (line.size() == 0) {
            sizes.push_back(size);
            return pair<int, bool>(size, true);
        }
        if (line == "$ cd ..") {
            sizes.push_back(size);
            return pair<int, bool>(size, false);
        } else {
            pair<int, bool> result = search_dir();
            size += result.first;
            if (result.second) {
                sizes.push_back(size);
                return pair<int, bool>(size, true);
            }
        }
    } while (getline(cin, line));
    sizes.push_back(size);
    return pair<int, bool>(size, true);
}

int main() {
    freopen("input.txt", "r", stdin);
    getline(cin, line);
    auto result = search_dir();
    int required = 30000000 - (70000000 - result.first);
    sort(sizes.begin(), sizes.end());
    auto index = lower_bound(sizes.begin(), sizes.end(), required);
    int file_size = sizes[index - sizes.begin()];
    printf("%d\n", file_size);
}

