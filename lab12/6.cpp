#include <iostream>
#include <algorithm>
#include <vector>
#include "fstream"

using namespace std;
int n;
ifstream in("selectw.in");
ofstream out("selectw.out");
vector<vector<int>> graph;
vector<int> used;
vector<pair<int, int>> state;
vector<int> cost;

void dfs(int v)
{
    used[v] = 1;
    for (auto to: graph[v])
    {
        if (!used[to])
        {
            dfs(to);
        }
        state[v].first += max(state[to].first, state[to].second);
        state[v].second += state[to].first;
    }
    state[v].second += cost[v];

}

int main()
{
    in >> n;
    graph.resize(n);
    state.resize(n);
    used.resize(n);
    cost.resize(n);
    int root;

    for (int i = 0; i < n; i++)
    {
        int temp, c;
        in >> temp;
        in >> c;
        temp -= 1;
        cost[i] = c;
        if (temp == -1)
        {
            root = i;
            continue;
        } else
        {
            graph[temp].push_back(i);
        }
    }

    dfs(root);

    out << max(state[root].first, state[root].second);

    retu