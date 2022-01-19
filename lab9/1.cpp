#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#define white 0
#define grey 1
#define black 2

using namespace std;

vector<int> ans;

void dfs(vector <vector<int>> &matrix, vector<int> &color, int v) {
    color[v] = grey;
    for (auto &x: matrix[v]) {
        if (color[x] == white) {
            dfs(matrix, color, x);
        } else if (color[x] == grey) {
            cout << -1;
            exit(0);
        }
    }
    ans.push_back(v + 1);
    color[v] = black;
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
    vector <vector<int>> matrix(n);
    vector<int> color(n);
    for (auto &x: color) {
        x = white;
    }

    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        matrix[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == white) {
            dfs(matrix, color, i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x: ans) {
        cout << x << ' ';
    }
}