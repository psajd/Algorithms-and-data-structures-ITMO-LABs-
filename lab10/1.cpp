#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> ans;
ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    out.tie(nullptr);

    int n, m;
    in >> n >> m;
    int a, b;
    ans.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        a--;
        b--;
        ans[a]++; ans[b]++;
    }
    for (auto x : ans){
        out << x << ' ';
    }
}