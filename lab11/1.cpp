#include <set>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
long long n, s, f;
ifstream in("pathmgep.in");
ofstream out("pathmgep.out");
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
    in >> n >> s >> f;
    s--;
    f--;
    dist.resize(n, INT64_MAX);
    g.resize(n, vector<long long>(n));
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            in >> g[i][j];
        }
    }

    dijkstra();
    out << ((dist[f] == INT64_MAX) ? -1 : dist[f]);

}