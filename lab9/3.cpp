#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#define white 0
#define grey 1
#define black 2

using namespace std;
vector<int> part;

void dfs(vector<vector<int>> &matrix, vector<int> &color, int v, int p) {
    color[v] = grey;
    part[v] = p;
    for (auto x: matrix[v]){
        if (color[x] == white){
            dfs(matrix, color, x, !p);
        }
        else if (color[x] == grey and part[x] == p){
            cout << "NO";
            exit(0);
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream in("input.txt");
    ifstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<vector<int>> matrix(n);
    vector<int> color(n);
    part.resize(n, -1);
    for (auto &x: color) {
        x = white;
    }

    int a, b;
    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        matrix[a].push_back(b); matrix[b].push_back(a);
    }

    for (int i = 0; i < n; ++i){
        if (color[i] == white){
            dfs(matrix, color, i, 0);
        }
    }
    cout << "YES";
    return 0;
}