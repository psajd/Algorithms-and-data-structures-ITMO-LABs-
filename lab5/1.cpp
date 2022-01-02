#include <bits/stdc++.h>

using namespace std;

const int mod = 1000029;
struct mySet {

    vector<vector<int>> set;

    mySet() {
        set.resize(mod);
    }

    int hash(int key) {
        return ((key % mod) + mod) % mod;
    }

    void add(int x) {
        int d = hash(x);
        for (int y: set[d]) {
            if (y == x) {
                return;
            }
        }
        set[d].push_back(x);
    }

    void del(int x) {
        int d = hash(x);
        for (int i = 0; i < set[d].size(); i++) {
            if (set[d][i] == x) {
                swap(set[d][i], set[d][set[d].size() - 1]);
                set[d].pop_back();
                return;
            }
        }
    }

    bool exists(int x) {
        int d = hash(x);
        for (int y: set[d]) {
            if (y == x) {
                return true;
            }
        }
        return false;
    }

};

int main() {

    ifstream cin("set.in");
    ofstream cout("set.out");

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string cmd;
    int key;

    mySet set;

    while (cin >> cmd){
        cin >> key;

        if (cmd == "insert"){
            set.add(key);
        }
        else if (cmd == "delete"){
            set.del(key);
        }
        else if (cmd == "exists"){
            bool status = set.exists(key);
            if (status){
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
        }
    }
}