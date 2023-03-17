#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<long long> p;
vector<long long> ans;
ifstream in("spantree3.in");
ofstream out("spantree3.out");
vector<pair<long long, pair<long long, long long>>> g;

long long dsu_get(long long v)
{
    return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(long long a, long long b)
{
    a = dsu_get(a);
    b = dsu_get(b);
    if (a != b)
    {
        p[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    out.tie(nullptr);

    long long n, m;
    in >> n >> m;
    g.resize(m);
    p.resize(n);
    for (long long i = 0; i < m; ++i)
    {
        long long a, b, c;
        in >> a >> b >> c;
        a--;
        b--;
        g[i] = make_pair(c, make_pair(a, b));
    }

    long long cost = 0;
    vector<pair<long long, long long> > res;
    sort(g.begin(), g.end());
    p.resize(n);

    for (long long i = 0; i < n; ++i)
    {
        p[i] = i;
    }

    for (long long i = 0; i < m; ++i)
    {
        long long a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if (dsu_get(a) != dsu_get(b))
        {
            cost += l;
            res.push_back(g[i].second);
            dsu_unite(a, b);
        }
    }

    out << cost;
}