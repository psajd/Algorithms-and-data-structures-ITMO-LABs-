#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
ifstream in("knapsack.in");
ofstream out("knapsack.out");

int main()
{

    int size, n;
    in >> size >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, (vector<int>(size + 1, 0)));


    for (int i = 0; i < n; ++i)
    {
        in >> a[i + 1];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            if (a[i] > j){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
            }
        }
    }

    out << dp[n][size];
    return 0;
}