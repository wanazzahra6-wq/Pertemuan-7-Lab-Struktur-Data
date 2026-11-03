#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cctype>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

    int charToIdx(char c) {
        return toupper(c) - 'A';
    }

    char idxToChar(int i) {
        return 'A' + i;
    }

public:
    Graph(int jumlahVertex) {
        V = jumlahVertex;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(char uChar, char vChar, int weight) {
        int u = charToIdx(uChar);
        int v = charToIdx(vChar);
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
        }
    }

    void dijkstraFromA() {
        int source = charToIdx('A');
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        distance[source] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "=== RUTE TERPENDEK DARI LOKASI A KE SEMUA LOKASI ===" << endl;
        for (int i = 0; i < V; i++) {
            cout << "A ke " << idxToChar(i) << " : ";
            if (distance[i] == INT_MAX) {
                cout << "Tidak terjangkau" << endl;
            } else {
                cout << "Total Jarak = " << distance[i] << " km | Rute: ";
                vector<int> path;
                for (int curr = i; curr != -1; curr = parent[curr]) {
                    path.push_back(curr);
                }
                reverse(path.begin(), path.end());
                for (size_t k = 0; k < path.size(); k++) {
                    cout << idxToChar(path[k]) << (k == path.size() - 1 ? "" : " -> ");
                }
                cout << endl;
            }
        }
    }

    void rekomendasiRute(char startChar, char endChar) {
        int source = charToIdx(startChar);
        int dest = charToIdx(endChar);

        if (source < 0 || source >= V || dest < 0 || dest >= V) {
            cout << "Input lokasi tidak valid!" << endl;
            return;
        }

        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        distance[source] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "\n=== REKOMENDASI RUTE TERCEPAT ===" << endl;
        if (distance[dest] == INT_MAX) {
            cout << "Tidak ada rute dari " << startChar << " ke " << endChar << endl;
        } else {
            cout << "Rute dari " << startChar << " ke " << endChar << " : ";
            vector<int> path;
            for (int curr = dest; curr != -1; curr = parent[curr]) {
                path.push_back(curr);
            }
            reverse(path.begin(), path.end());

            for (size_t k = 0; k < path.size(); k++) {
                cout << idxToChar(path[k]) << (k == path.size() - 1 ? "" : " -> ");
            }
            cout << "\nTotal Jarak: " << distance[dest] << " km" << endl;
        }
    }
};

int main() {
    // 6 titik lokasi A-F
    Graph graph(6);

    // Input data jarak sesuai gambar
    graph.addEdge('A', 'B', 4);
    graph.addEdge('A', 'C', 2);
    graph.addEdge('B', 'C', 1);
    graph.addEdge('B', 'D', 5);
    graph.addEdge('B', 'E', 3);
    graph.addEdge('C', 'D', 8);
    graph.addEdge('C', 'E', 6);
    graph.addEdge('D', 'E', 2);
    graph.addEdge('D', 'F', 4);
    graph.addEdge('E', 'F', 3);

    graph.dijkstraFromA();

    cout << "\n----------------------------------------" << endl;
    char awal, tujuan;
    cout << "Masukkan Lokasi Asal (A-F)   : ";
    cin >> awal;
    cout << "Masukkan Lokasi Tujuan (A-F) : ";
    cin >> tujuan;

    graph.rekomendasiRute(awal, tujuan);

    return 0;
}