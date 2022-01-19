#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> g, vector<int> &dist, int n, int s) {
    queue<int> pointQueue;
    vector<bool> used(n, false);

    used[s] = true;
    pointQueue.push(s);

    while (!pointQueue.empty()) {
        int v = pointQueue.front();
        pointQueue.pop();
        for (auto &x: g[v]) {
            if (!used[x]){
                used[x] = true;
                pointQueue.push(x);
                dist[x] = dist[v] + 1;
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

    vector<vector<int>> graph(n);

    dist.resize(n, 0);

    int a, b;
    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int s = 0;
    bfs(graph, dist, n, s);

    for (auto x : dist){
        cout << x << ' ';
    }

    return 0;
}