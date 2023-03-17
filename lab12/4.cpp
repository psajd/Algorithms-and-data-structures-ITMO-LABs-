#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
ifstream in("knight2.in");
ofstream out("knight2.out");

int main()
{

    int n, m;
    in >> n >> m;
    vector<vector<int>> ans(n + 3, vector<int>(m + 3));
    ans[2][2] = 1;
    int i_ = 2, j_ = 2;

    while ((i_ < n + 1) or (j_ < m + 1))
    {
        if (j_ == m + 1) { i_++; } else { j_++; }
        int i = i_, j = j_;
        while ((i <= n + 1) and j >= 2)
        {
            ans[i][j] = ans[i + 1][j - 2] + ans[i - 1][j - 2] + ans[i - 2][j - 1] + ans[i - 2][j + 1];
            i++;
            j--;
        }
    }

    out << ans[n + 1][m + 1];
    return 0;
}