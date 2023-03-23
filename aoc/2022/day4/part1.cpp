#include <iostream>
#include <fstream>

using namespace std;

int main() {
    auto inputFile = fopen("input.txt", "r");

    int start1, end1, start2, end2;
    int result = 0;
    while (fscanf(inputFile, "%d-%d,%d-%d\n", &start1, &end1, &start2, &end2) != EOF) {
        if ((start1 <= start2 && end1 >= end2) || (start2 <= start1 && end2 >= end1)) {
            result++;
        }
    }
    printf("%d\n", result);
}