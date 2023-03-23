#include <iostream>

using namespace std;

int robs[4];
int cost[4][4];
int resources[4];
int max_cost[4];
int record = 0;
int time_left;

bool dfs(int robot) {
    if (robs[robot]+1 > max_cost[robot]) return false;
    int time_to_buy = 0;
    bool can_buy = true;
    for (int i = 0; i < 4; i++) {
        if (cost[robot][i] == 0) continue;
        if (robs[i] == 0) {
            can_buy = false;
            break;
        }
        time_to_buy = max(time_to_buy, (max(cost[robot][i]-resources[i], 0)+robs[i]-1)/robs[i]);
    }
    time_to_buy++;
    if ((time_left <= time_to_buy) || !can_buy) return false;

    time_left -= time_to_buy;
    for (int i = 0; i < 4; i++) {
        resources[i] += robs[i]*time_to_buy-cost[robot][i];
    }
    robs[robot]++;

    bool end = true;
    for (int i = 0; i < 4; i++) {
        if (dfs(i)) end = false;
    }

    if (end) {
        int score = resources[3] + robs[3]*time_left;
        if (score > record) record = score;
    }

    robs[robot]--;
    for (int i = 0; i < 4; i++) {
        resources[i] -= robs[i]*time_to_buy-cost[robot][i];
    }
    time_left += time_to_buy;
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int tot = 1;
    int i = 1;
    while (getline(cin, line) && i <= 3) {
        int colon = line.find(':', 0);
        int period1 = line.find('.', colon+1);
        int period2 = line.find('.', period1+1);
        int o1 = line.find('o', period2+28);
        int period3 = line.find('.', period2+1);
        int o2 = line.find('o', period3+25);

        cost[0][0] = stoi(line.substr(colon+23, period1-colon-27));
        cost[1][0] = stoi(line.substr(period1+24, period2-period1-28));
        cost[2][0] = stoi(line.substr(period2+28, o1-period2-29));
        cost[2][1] = stoi(line.substr(o1+8, period3-o1-13));
        cost[3][0] = stoi(line.substr(period3+25, o2-period3-26));
        cost[3][2] = stoi(line.substr(o2+8, line.size()-o2-16));

        for (int j = 0; j < 4; j++) {
            robs[j] = 0;
            resources[j] = 0;
            for (int k = 0; k < 4; k++) {
                max_cost[j] = max(max_cost[j], cost[k][j]);
            }
        }
        robs[0] = 1;
        max_cost[3] = INT_MAX;
        
        record = 0;

        time_left = 32;

        for (int i = 0; i < 4; i++) {
            dfs(i);
        }

        printf("%d\n", record);
        tot *= record;
        i++;
    }
    printf("%d\n", tot);
}