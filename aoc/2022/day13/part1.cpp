#include <iostream>
#include <string>

using namespace std;

int compare(const string& left, const string& right) {
    printf("%s %s\n", left.c_str(), right.c_str());
    if (left[0] != '[' && right[0] != '[') {
        int left_int = stoi(left);
        int right_int = stoi(right);
        if (left_int < right_int) {
            return 1;
        } else if (left_int > right_int) {
            return -1;
        }
        return 0;
    } else {
        int last_left = 0;
        int left_n = 0;

        int last_right = 0;
        int right_n = 0;
        while (true) {
            int left_start, left_end;
            bool left_left;
            for (int i = last_left; i < left.size(); i++) {
                if (left[i] == '[') {
                    left_n++;
                } else if (left[i] == ']') {
                    left_n--;
                } else if (left[i] == ',') {
                    if (left_n == 1) {
                        left_start = last_left+1;
                        left_end = i;
                        last_left = i;
                        left_left = false;
                        break;
                    }
                }
            }
            printf("%d %d\n", left_start, left_end);

            int right_start, right_end;
            bool right_left;
            for (int i = last_right; i < right.size(); i++) {
                if (right[i] == '[') {
                    right_n++;
                } else if (left[i] == ']') {
                    right_n--;
                } else if (left[i] == ',') {
                    if (right_n == 1) {
                        right_start = last_right+1;
                        right_end = i;
                        last_right = i;
                        right_left = false;
                        break;
                    }
                }
            }
            printf("%d %d\n", right_start, right_end);

            int result = compare(left.substr(left_start, left_end-left_start), right.substr(right_start, right_end-right_start));
            printf("%d\n", result);

            if (last_left > 3) break;

            if (result == 0) continue;
            return result;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    string l1, l2;
    do {
        getline(cin, l1);
        getline(cin, l2);
        compare(l1, l2);
        break;
    } while (getline(cin, l1));
}