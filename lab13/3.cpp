#include <iostream>
#include <algorithm>
#include <vector>
#include "fstream"


using namespace std;
vector<vector<long long>> dp;
vector<long long> arr;
ifstream in("prefix.in");
ofstream out("prefix.out");

vector<int> prefix_function(const string &s)
{
    int n = s.length();
    vector<int> a(n);
    for (int i = 1; i < n; ++i)
    {
        int j = a[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = a[j - 1];
        }
        if (s[i] == s[j])
        {
            ++j;
        }
        a[i] = j;
    }
    return a;
}

int main()
{
    string s;
    in >> s;
    auto a = prefix_function(s);
    for (int i: a)
    {
        out << i << ' ';
    }
    return 0;
}