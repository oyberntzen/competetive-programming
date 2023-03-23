#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
    freopen("julebrusmaskiner.txt", "r", stdin);

    string line;
    unordered_map<string, int> p;
    int record = 0;
    int total = 0;
    string recordName;
    while (getline(cin, line)) {
        replace(line.begin(), line.end(), ' ', '!');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        
        string s1, s2, s3, s4;
        ss >> s1 >> s2 >> s3 >> s4;

        string m = s1.substr(7, s1.size()-7);
        int t = stoi(s2.substr(12, s2.size()-12));
        int v = stoi(s3.substr(6, s3.size()-6));
        int k = stoi(s4.substr(10, s4.size()-10));

        //printf("%s %d %d %d\n", m.c_str(), t, v, k);

        if (t < 95 || t > 105) continue;
        if (v < 400 || v > 1500) continue;
        if (k < 300 || k > 500) continue;

        

        double v1 = double(v-100) + double(k)/10.0;
        double v2 = 0;
        if (t >= 100) {
            v2 = v1/40;
        }
        int v3 = int(v1) - int(v2);
        //printf("%d\n", v3);

        if (p.find(m) == p.end()) {
            p[m] = 0;
        }
        p[m] += v3;
        total += v3;
        if (p[m] > record) {
            record = p[m];
            recordName = m;
        }
    }

    printf("%d %s\n", total, recordName.c_str());
}