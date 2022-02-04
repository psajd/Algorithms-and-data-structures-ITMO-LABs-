#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#define white 0
#define grey 1
#define black 2

using namespace std;

vector<int> order;

void dfs1(vector<vector<int>> &matrix, vector<int> &color, int v) {
    color[v] = grey;
    for (auto &x: matrix[v]) {
        if (color[x] == white) {
            dfs1(matrix, color, x);
        }
    }
    order.push_back(v);
    color[v] = black;
}

void dfs2(vector<vector<int>> &matrix_tr, vector<int> &color, vector<int> &component, int v, int c) {
    color[v] = grey;
    component[v] = c;
    for (auto &x :matrix_tr[v]){
        if (color[x] == white){
            dfs2(matrix_tr, color, component, x, c);
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

    int a, b;
    vector<vector<int>> matrix(n);
    vector<vector<int>> matrix_tr(n);
    vector<int> color(n);
    vector<int> component(n);
    for (auto &x: color) {
        x = white;
    }

    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        matrix[a].push_back(b);
        matrix_tr[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == white) {
            dfs1(matrix, color, i);
        }
    }
    reverse(order.begin(), order.end());
    color.assign(n, white);

    int c = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[i];
        if (color[v] == white) {
            c++;
            dfs2(matrix_tr, color, component, v, c);
        }
    }

    for (auto x: component){
        cout << x << ' ';
    }
}