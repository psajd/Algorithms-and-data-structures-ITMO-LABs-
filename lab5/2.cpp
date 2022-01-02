#include <bits/stdc++.h>

using namespace std;

const int mod = 1000029;
struct myMap {

    vector<vector<pair<string, string>>> map;

    myMap() {
        map.resize(mod);
    }

    int hash(string x) {
        int hash = 0;
        for (int i = 0; i < x.size(); i++) {
            hash *= 47;
            hash += x[i] - 'a' + 1;
            hash = ((hash % mod) + mod) % mod;
        }
        hash %= mod;
        return hash;
    }

    void put(string x, string y) {
        int d = hash(x);
        for (auto& h : map[d]) {
            if (x == h.first) {
                h.second = y;
                return;
            }
        }
        map[d].push_back(make_pair(x, y));
    }

    void del(string x) {
        int d = hash(x);
        for (int i = 0; i < map[d].size(); i++) {
            if (map[d][i].first == x) {
                swap(map[d][i], map[d][map[d].size() - 1]);
                map[d].pop_back();
                return;
            }
        }
    }

    string get(string x) {
        int d = hash(x);
        for (int i = 0; i < map[d].size(); i++){
            if (map[d][i].first == x){
                return map[d][i].second;
            }
        }
        return "none";
    }
};

int main() {

    ifstream cin("map.in");
    ofstream cout("map.out");

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string cmd, x, y;
    myMap map;

    while (cin >> cmd){

        cin >> x;

        if (cmd == "put"){
            cin >> y;
            map.put(x, y);
        }
        else if (cmd == "get"){
            cout << map.get(x) << endl;
        }
        else if (cmd == "delete"){
            map.del(x);
        }
    }
}