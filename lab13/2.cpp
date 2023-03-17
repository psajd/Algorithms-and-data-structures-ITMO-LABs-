#include <iostream>
#include <algorithm>
#include <vector>
#include "fstream"


using namespace std;
vector<vector<long long>> dp;
vector<long long> arr;
ifstream in("search2.in");
ofstream out("search2.out");

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

vector<int> kmp(const string &p, const string &t)
{
    int p_size = (int) p.size();
    int t_size = (int) t.size();
    vector<int> result;
    string temp = p + "#" + t;
    vector<int> prefix = prefix_function(temp);
    int count = 0;
    for (int i = 0; i < t_size; ++i)
    {
        if (prefix[p_size + i + 1] == p_size)
        {
            count++;
            result.push_back(i - p_size + 1);
        }
    }
    return result;
}


int main()
{
    string p, t;
    in >> p >> t;
    auto a = kmp(p, t);
    out << a.size() << endl;
    for (int i: a)
    {
        out << i  + 1 << ' ';
    }
    return 0;
}