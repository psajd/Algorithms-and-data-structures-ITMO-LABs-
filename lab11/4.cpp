#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

ifstream in("negcycle.in");
ofstream out("negcycle.out");

struct edge
{
    int a_, b_, cost_;

    edge(int a, int b, int cost) : a_(a), b_(b), cost_(cost) {}
};

vector<edge> e; // рёбра
int n, m;
static const int no_edge = 1000000000;
vector<int> d; // расстояния
vector<int> p; // предки
int x;


void bfa()
{
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j = 0; j < m; ++j)
            if (d[e[j].b_] > d[e[j].a_] + e[j].cost_)
            {
                d[e[j].b_] = max(-1000000000, d[e[j].a_] + e[j].cost_);
                p[e[j].b_] = e[j].a_;
                x = e[j].b_;
            }
    }
}

int main()
{
    in >> n;
    d.resize(n);
    p.resize(n - 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int cost;
            in >> cost;
            if (cost != no_edge)
            {
                e.emplace_back(i, j, cost);
                m++;
            }
        }
    }


    d.resize(n);
    p.resize(n, -1);
    bfa();

    if (x == -1)
    {
        out << "NO";
    } else
    {
        int y = x;
        for (int i = 0; i < n; ++i)
        {
            y = p[y];
        }
        vector<int> ans;
        for (int cur = y;; cur = p[cur])
        {
            ans.push_back(cur);
            if (cur == y && ans.size() > 1) break;
        }

        reverse(ans.begin(), ans.end());

        out << "YES" << endl << ans.size() << endl;
        for (int i: ans)
        {
            out << i + 1 << ' ';
        }
    }

}