#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> g;
    set<pair<int, int>> g_set;

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;

    in >> n >> m;

    for (int i = 0; i < m; ++i){
        pair<int, int> p;
        in >> p.first >> p.second;
        if (p.first > p.second){
            swap(p.first, p.second);
        }
        g.push_back(p);
        g_set.insert(p);
    }

    if (g.size() == g_set.size()){
        out << "NO";
    }
    else{
        out << "YES";
    }

    return 0;
}
