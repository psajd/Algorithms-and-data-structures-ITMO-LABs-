#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include "cmath"

using namespace std;


vector<pair<int, int>> cords;
ifstream in("spantree.in");
ofstream out("spantree.out");

double get_length(int a, int b){
    return sqrt((cords[a].first - cords[b].first) * (cords[a].first - cords[b].first) +
                (cords[a].second - cords[b].second) * (cords[a].second - cords[b].second));
}

int main()
{
    int n;
    in >> n;
    cords.resize(n);
    vector<int> u(n);
    vector<double> minE(n, 1000000000000000);
    minE[0] = 0;
    double cost = 0;

    for (int i = 0; i < n; i++)
        in >> cords[i].first >> cords[i].second;


    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!u[j] && (v == -1 || minE[j] < minE[v]))
                v = j;

        cost += minE[v];
        u[v] = 1;

        for (int j = 0; j < n; j++)
        {
            double x = (get_length(v, j));
            if (x < minE[j])
                minE[j] = x;
        }
    }

    out << fixed << setprecision(20) << cost << endl;
}