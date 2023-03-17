#include <set>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
long long n, m, s;
ifstream in("pathsg.in");
ofstream out("pathsg.out");
vector<vector<long long>> g;
vector<long long> dist;

void dijkstra()
{
    set<pair<long long, long long>> q;
    dist[s] = 0;
    q.insert(make_pair(dist[s], s));
    while (!q.empty())
    {
        long long v = q.begin()->second;
        q.erase(q.begin());
        for (size_t j = 0; j < g[v].size(); ++j)
        {
            if (g[v][j] == -1 || v == j) { continue; }
            if (dist[j] > dist[v] + g[v][j])
            {
                q.erase({dist[j], j});
                dist[j] = dist[v] + g[v][j];
                q.insert({dist[j], j});
            }
        }
    }
}


int main()
{
    in >> n >> m;
    g.resize(n, vector<long long>(n, -1));
    dist.resize(n, INT64_MAX);
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, cost;
        in >> a >> b >> cost;
        a--;
        b--;
        g[a][b] = cost;
    }

    for (size_t i = 0; i < n; ++i)
    {
        s = (long long)i;
        for (auto &x : dist){
            x = INT64_MAX;
        }
        dijkstra();
        for (auto x : dist){
            out << x << ' ';
        }
        out << endl;

    }

}