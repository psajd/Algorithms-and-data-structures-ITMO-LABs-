#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> g, vector<int> &dist, vector<bool> &used, int s, int c) {
    queue<int> pointQueue;
    used[s] = true;
    pointQueue.push(s);
    dist[s] = c;
    while (!pointQueue.empty()) {
        int v = pointQueue.front();
        pointQueue.pop();
        for (auto &x: g[v]) {
            if (!used[x]){
                used[x] = true;
                pointQueue.push(x);
                dist[x] = c;
            }
        }
    }
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<int> dist;
    vector<bool> used(n, false);
    vector<vector<int>> graph(n);

    dist.resize(n, 1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int c = 0;
    for (int i = 0; i < n; ++i){
        if (!used[i]){
            c++;
            bfs(graph, dist, used, i, c);
        }
    }

    cout << c << endl;

    for (auto x : dist){
        cout << x << ' ';
    }
    return 0;
}

