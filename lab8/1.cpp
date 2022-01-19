#include <iostream>
#include <fstream>

using namespace std;

struct graph{
    int vertexes, edges;
    int **matrix;

    void createMatrix(){
        matrix = new int*[vertexes];
        for (int i = 0; i < vertexes; ++i){
            matrix[i] = new int[vertexes];
            for (int j = 0; j < vertexes; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void show() const{
        ofstream out("output.txt");
        for(int i = 0; i < vertexes; ++i){
            for (int j = 0; j < vertexes; j++){
                out << matrix[i][j] << ' ';
            }
            out << endl;
        }
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream in("input.txt");


    graph g{};
    in >> g.vertexes >> g.edges;
    g.createMatrix();

    int a, b;

    for (int i = 0; i < g.edges; ++i){
        in >> a >> b;
        g.matrix[a-1][b-1] = 1;
    }

    g.show();

    return 0;
}
