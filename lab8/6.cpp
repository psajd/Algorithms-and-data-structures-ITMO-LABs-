#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> x = {1, -1, 0, 0};      // R L U D
    vector<int> y = {0, 0, 1, -1};

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    string temp;
    vector<vector<int>> map;
    map.resize(n, vector<int>(m));

    vector<vector<bool>> used;
    used.resize(n, vector<bool>(m));

    vector<vector<pair<int, int>>> par;
    par.resize(n, vector<pair<int, int>>(m));

    pair<int, int> start, finish;
    queue<pair<int, int>> q;


    for (int i = 0; i < n; ++i) {
        in >> temp;
        for (int j = 0; j < m; ++j) {
            if (temp[j] == '.') {
                map[i][j] = 1;
            } else if (temp[j] == '#') {
                map[i][j] = 0;
            } else if (temp[j] == 'S') {
                map[i][j] = 1;
                start = make_pair(i, j);
            } else if (temp[j] == 'T') {
                map[i][j] = 1;
                finish = make_pair(i, j);
            }
            used[i][j] = false;
            par[i][j] = {-1, -1};
        }
    }

    /*for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }*/
    bool flag = false;
    q.push(start);
    used[start.first][start.second] = true;
    while (!q.empty())
    {
        pair v = q.front();
        q.pop();
        if (v == finish)
        {
            flag = true;
            break;
        }
        //cout << "====" << v.first << ' ' << v.second << endl;
        for (int i = 0; i < 4; ++i) {
            if ((v.first + x[i] < n) and (v.first + x[i] >= 0) and (v.second + y[i] < m) and (v.second + y[i] >= 0))
            {
                if (map[v.first + x[i]][v.second + y[i]] and !used[v.first + x[i]][v.second + y[i]]){
                    used[v.first + x[i]][v.second + y[i]] = true;
                    q.push(make_pair(v.first + x[i], v.second + y[i]));
                    par[v.first + x[i]][v.second + y[i]] = {v.first, v.second};
                }
            }
        }
    }
    if (!flag){
        cout << -1;
        return 0;
    }


    /*for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << used[i][j] << ' ';
        }
        cout << endl;
    }*/


    pair t = {-1, -1};
    string path;
    int pathLen = -1;

    for (pair i = finish; i != t; i = par[i.first][i.second]){
        pair mv = {i.first - par[i.first][i.second].first, i.second - par[i.first][i.second].second};
        if (mv.first == 1 and mv.second == 0){
            path.append("D");
        }
        else if (mv.first == -1 and mv.second == 0){
            path.append("U");
        }
        else if (mv.first == 0 and mv.second == 1){
            path.append("R");
        }
        else if (mv.first == 0 and mv.second == -1){
            path.append("L");
        }
        pathLen++;
    }
    reverse(path.begin(), path.end());
    cout << pathLen << endl << path;
    return 0;
}

