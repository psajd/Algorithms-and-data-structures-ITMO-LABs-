#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#define white 0
#define grey 1
#define black 2

using namespace std;
vector<int> p;
int cycle_start = -1, cycle_end = -1;

bool dfs(vector<vector<int>> &matrix, vector<int> &color, int v) {
    color[v] = grey;
    for (auto &x: matrix[v]) {
        if (color[x] == white) {
            p[x] = v;
            if (dfs(matrix, color, x)) {
                return true;
            }
        } else if (color[x] == grey) {
            cycle_end = v;
            cycle_start = x;
            return true;
        }
    }
    color[v] = black;
    return false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream in("input.txt");
    ifstream out("output.txt");

    int n, m;
    in >> n >> m;

    int a, b;
    vector<vector<int>> matrix(n);
    vector<int> color(n);
    for (auto &x: color) {
        x = white;
    }
    p.resize(n, -1);

    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        matrix[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == white) {
            if (dfs(matrix, color, i)){
                break;
            }
        }
    }

    if (cycle_start == -1){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = p[v]){
            cycle.push_back(v);
        }
        reverse(cycle.begin(), cycle.end());
        for (auto x : cycle){
            cout << x + 1 << ' ';
        }
    }
}
