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

        void addEdge(int i, int j) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
        adjMatrix[i][j] =1; // I kk dewi, J dinda berarti i ke j
        adjMatrix[j][i] =1; // J dinda, I kk dewi berarti j ke i

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

void dfs(int startvertex) { // start index mau dari berapa
    vector<bool> visited(numberVertex, false); // inisialisasi semua vertex belum dikunjungi
    dfsUntil(startvertex, visited); // ketika dfs kita mulai dari yang awal yang kita mau
}

void dfsUntil(int currentVertex, vector<bool>& visited) {
    visited[currentVertex] = true;
    cout << "Visited: " << currentVertex << endl; // vertex yang sedang dikunjungi

    for (int i = 0; i < numberVertex; i++) {
        if (adjMatrix[currentVertex][i] == 1 && !visited[i]) { // apakah ada hhubungan anatar vertex si a dengan si i
            dfsUntil(i, visited); 
        }
    }
}

};

int main() {
    Graph graphh(8);
    
    graphh.addEdge(0,1);
    graphh.addEdge(0,2);
    graphh.addEdge(1,3);
    graphh.addEdge(1,4);
    graphh.addEdge(2,5);
    graphh.addEdge(3,6);
    graphh.addEdge(5,7);

    graphh.printAdjMatrix();
    cout << endl;

    graphh.dfs(0);
    return 0;
}