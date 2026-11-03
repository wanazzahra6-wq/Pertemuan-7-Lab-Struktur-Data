#include<iostream>
#include<vector>
using namespace std;

class Graph {
    private: 
    int numberVertex;// simpan jumlah vertex
    vector<vector<int>> adjMatrix; // simpan hubungan antr vertex

    public:
    Graph (int banyakTitik) { // banyak jumlha titik yang mau kita buat
        numberVertex = banyakTitik; 
        adjMatrix.resize(numberVertex, vector<int> (numberVertex, 0));
        
    }

        void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
        adjMatrix[i][j] = weight; // I kk dewi, J dinda berarti i ke j
        adjMatrix[j][i] = weight; // J dinda, I kk dewi berarti j ke i

        } else {
            cout << "index nonvalid" << endl;

        }

}

void printAdjMatrix() {
    for (int i = 0; i < numberVertex; i++) { // utk perpindahan looping dari baris 1 ke 2, 2 ke 3.
        for (int j = 0; j < numberVertex; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

};

int main() {
    Graph graphh(5); // buat graph dengan 5 vertex (0, 1, 2, 3, 4)

    graphh.addEdge(0, 1, 5);
    graphh.addEdge(0, 2, 3);
    graphh.addEdge(1, 3, 4);
    graphh.addEdge(1, 4, 7);
    graphh.addEdge(2, 3, 2);
    graphh.addEdge(3, 4, 8);
    

    cout << "Adjacency Matrix: " << endl;
    graphh.printAdjMatrix();

    return 0;
}