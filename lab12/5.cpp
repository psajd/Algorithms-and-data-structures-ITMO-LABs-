#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int n;
vector<vector<int>> graph;
vector<int> used;
vector<pair<int, int>> state;

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
    state[v].second++;

}

int main()
{
    cin >> n;
    graph.resize(n);
    state.resize(n);
    used.resize(n);
    int root;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp -= 1;
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

    cout << max(state[root].first, state[root].second);

    return 0;
}