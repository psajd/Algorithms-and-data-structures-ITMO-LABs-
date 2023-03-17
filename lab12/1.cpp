#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{

    int n;
    cin >> n;
    vector<int> pos(n + 1), prev(n + 1), values(n + 1, INT32_MAX), data(n + 1);
    values[0] = INT32_MIN;
    pos[0] = -1;
    int length = 0;

    for (size_t i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        data[i] = temp;
    }

    for (size_t i = 0; i < n; ++i)
    {
        int j = (int) (upper_bound(values.begin(), values.end(), data[i]) - values.begin());
        if (values[j - 1] < data[i] and data[i] < values[j])
        {
            values[j] = data[i];
            pos[j] = (int)i;
            prev[i] = pos[j - 1];
            length = max(length, j);
        }
    }
    vector<int> ans;
    for (int p = pos[length]; p != -1; p = prev[p]){
        ans.push_back(data[p]);
    }
    reverse(ans.begin(), ans.end());
    cout << length << '\n';
    for (auto x : ans){
        cout << x << ' ';
    }
}