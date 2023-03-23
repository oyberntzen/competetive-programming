#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> flow_rates;
vector<vector<int> > tunnels;
vector<int> lengths;
vector<int> nodes;
vector<vector<int> > edges;
int start_node;

void search1(int node, int length) {
    if (length < lengths[node] || lengths[node] == -1) {
        lengths[node] = length;
        for (int i = 0; i < tunnels[node].size(); i++) {
            search1(tunnels[node][i], length+1);
        }
    }
}

int record = 0;
vector<bool> visited;

void search3(int node, int time, int score) {
    //printf("%d %d\n", score, node);
    if (score > record) {
        record = score;
    }
    for (int i = 0; i < edges[node].size(); i++) {
        if (!visited[i]) {
            int new_time = time+edges[node][i]+1;
            if (new_time < 26) {
                visited[i] = true;
                search3(i, new_time, score+flow_rates[nodes[i]]*(26-new_time));
                visited[i] = false;
            }
        }
    }
}

void search2(int node, int time, int score) {
    //printf("%d %d\n", score, node);
    search3(start_node, 0, score);
    for (int i = 0; i < edges[node].size(); i++) {
        if (!visited[i]) {
            int new_time = time+edges[node][i]+1;
            if (new_time < 26) {
                visited[i] = true;
                search2(i, new_time, score+flow_rates[nodes[i]]*(26-new_time));
                visited[i] = false;
            }
        }
    }
}


int main() {
    freopen("input.txt", "r", stdin);

    map<string, int> valve_names;
    vector<string> tunnels_strings;
    string line;
    int i = 0;
    int start;
    while (getline(cin, line)) {
        string valve_name = line.substr(6, 2);
        valve_names[valve_name] = i;
        int semicolon = line.find(';');
        int flow_rate = stoi(line.substr(23, semicolon-23));
        flow_rates.push_back(flow_rate);
        if (line.size()-semicolon-25 == 1) {
            tunnels_strings.push_back(line.substr(line.size()-2, 2));
        } else {
            tunnels_strings.push_back(line.substr(semicolon+25, line.size()-semicolon-25));
        }
        if (flow_rate != 0 || valve_name == "AA") {
            nodes.push_back(i);
        }
        if (valve_name == "AA") start = i;
        i++;
    }
    
    tunnels.resize(tunnels_strings.size());
    for (int i = 0; i < tunnels_strings.size(); i++) {
        int num = (tunnels_strings[i].size()+2)/4;
        for (int j = 0; j < num; j++) {
            tunnels[i].push_back(valve_names[tunnels_strings[i].substr(j*4, 2)]);
        }
    }
    
    lengths.resize(tunnels.size());
    edges.resize(nodes.size());
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = 0; j < lengths.size(); j++) {
            lengths[j] = -1;
        }
        search1(nodes[i], 0);

        edges[i].resize(nodes.size());
        for (int j = 0; j < nodes.size(); j++) {
            edges[i][j] = lengths[nodes[j]];
            //printf("%d %d %d\n", i, j, lengths[nodes[j]]);
        }
    }

    
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == start) {
            visited.push_back(true);
            start_node = i;
        }
        else visited.push_back(false);
    }
    search2(start_node, 0, 0);
    printf("%d\n", record);
}