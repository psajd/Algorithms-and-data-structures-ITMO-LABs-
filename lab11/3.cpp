#include <set>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
int n, m, s = 0;
ifstream in("pathbgep.in");
ofstream out("pathbgep.out");
vector<vector<pair<int, int>>> g; // список смежности вместо матрицы
vector<int> dist;

void dijkstra()
{
    set<pair<int, int>> q;
    dist[s] = 0;
    q.insert(make_pair(dist[s], s));
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (size_t j = 0; j < g[v].size(); ++j)
        {
            if (g[v][j].second == -1 || g[v][j].first == v) { continue; }

            if (dist[g[v][j].first] > dist[v] + g[v][j].second)
            {
                q.erase({dist[g[v][j].first], g[v][j].first});
                dist[g[v][j].first] = dist[v] + g[v][j].second;
                q.insert({dist[g[v][j].first], g[v][j].first});
            }
        }
    }
}


int main()
{
    in >> n >> m;
    g.resize(n);
    dist.resize(n, INT_MAX);
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, cost;
        in >> a >> b >> cost;
        a--;
        b--;
        g[a].push_back(make_pair(b, cost));
        g[b].push_back(make_pair(a, cost));
    }

    dijkstra();
    for (auto x: dist)
    {
        out << x << ' ';
    }


}