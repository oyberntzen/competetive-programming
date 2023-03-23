#include <iostream>
#include <string>

using namespace std;
string line;
int directories = 0;

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
        if (size <= 100000) {
            directories += size;
        }
        return pair<int, bool>(size, true);
    }

    do {
        if (line.size() == 0) {
            if (size <= 100000) {
                directories += size;
            }
            return pair<int, bool>(size, true);
        }
        if (line == "$ cd ..") {
            if (size <= 100000) {
                directories += size;
            }
            return pair<int, bool>(size, false);
        } else {
            pair<int, bool> result = search_dir();
            size += result.first;
            if (result.second) {
                if (size <= 100000) {
                    directories += size;
                }
                return pair<int, bool>(size, true);
            }
        }
    } while (getline(cin, line));
    if (size <= 100000) {
        directories += size;
    }
    return pair<int, bool>(size, true);
}

int main() {
    freopen("input.txt", "r", stdin);
    getline(cin, line);
    auto result = search_dir();
    printf("%d\n", directories);
}

