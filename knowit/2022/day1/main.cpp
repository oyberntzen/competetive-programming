#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<pair<string, string> > > dicts;
string letter;
vector<string> translated;
int maxLen;

bool search(int i) {
    if (i == letter.size()) return true;
    for (int length = 0; length <= min(maxLen, int(letter.size()-i)); length++) {
        string word = letter.substr(i, length);
        for (int j = 0; j < dicts[length].size(); j++) {
            if (dicts[length][j].first == word) {
                translated.push_back(dicts[length][j].second);
                if (search(i + length)) return true;
                translated.pop_back();
            }
        }
    }
}

int main() {
    fstream dictFile("dictionary.txt");

    string currentLine;
    vector<pair<string, string> > dict;
    
    while (getline(dictFile, currentLine)) {
        int delimiter;
        for (int i = 0; i < currentLine.size(); i++) {
            if (currentLine[i] == ',') {
                delimiter = i;
                break;
            }
        }
        dict.push_back(pair<string, string>(currentLine.substr(0, delimiter), currentLine.substr(delimiter+1, currentLine.size()-delimiter)));
        maxLen = max(maxLen, int(currentLine.size()));
    }
    dictFile.close();

    sort(dict.begin(), dict.end());

    for (int i = 0; i < maxLen; i++) {
        dicts.push_back(vector<pair<string, string> >());
    }

    for (int i = 0; i < dict.size(); i++) {
        dicts[dict[i].first.size()].push_back(dict[i]);
    }

    fstream letterFile("letter.txt");
    
    getline(letterFile, letter);
    letterFile.close();

    search(0);

    int length = translated.size()-1;
    for (string word : translated) {
        length += word.size();
    }

    cout << length << endl;
}