#include <iostream>
#include <fstream>

using namespace std;

struct graph{
    int vertexes;
    int **matrix;

    void createMatrix()
    {
        ifstream in("input.txt");
        in >> vertexes;
        matrix = new int*[vertexes];
        for (int i = 0; i < vertexes; ++i){
            matrix[i] = new int[vertexes];
            for (int j = 0; j < vertexes; j++){
                in >> matrix[i][j];
            }
        }
    }

    void show() const
    {
        for(int i = 0; i < vertexes; ++i)
        {
            for (int j = 0; j < vertexes; j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }

    [[nodiscard]] bool is_Disorientated() const
    {
        for(int i = 0; i < vertexes; ++i)
        {
            for (int j = 0; j < vertexes; j++)
            {
                if (i == j and matrix[i][j] == 1)
                {
                    return false;
                }
                if (matrix[i][j] != matrix[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ofstream out("output.txt");

    graph g{};
    g.createMatrix();

    if (g.is_Disorientated())
    {
        out << "YES";
    }
    else
    {
        out << "NO";
    }

    //cout << endl;
    //g.show();

    return 0;
}