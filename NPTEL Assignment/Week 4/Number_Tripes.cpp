#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Edge {
    int vertex;
    int weight;
};

int main() {
    int M, A, B;

    map<int, int> vertexMapping;
    cin >> M >> A >> B;

    // Initialize an empty vector of vectors
    vector<vector<Edge>> chain(M);
    int uniqueIndex = 0;


    for (int i = 0; i < M; i++) {
        int u, w, v;
        cin >> u >> w >> v;

        if(vertexMapping.find(u) == vertexMapping.end()){
            vertexMapping[u] = uniqueIndex++;
        }

        if(vertexMapping.find(v) == vertexMapping.end()){
            vertexMapping[v] = uniqueIndex++;
        }

        if(max(vertexMapping[u], vertexMapping[v]) >= chain.size()){
            chain.resize(max(vertexMapping[u], vertexMapping[v]) + 1);
        }

        u = uniqueIndex;
        v = uniqueIndex;

        // Create edges and add them to the adjacency lists
        chain[u].push_back({v, w});
        chain[v].push_back({u, w});
    }

    // Print the adjacency lists
    for (int i = 0; i < chain.size(); i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (const Edge& edge : chain[i]) {
            cout << "(" << edge.vertex << ", " << edge.weight << ") ";
        }
        cout << endl;
    }

    return 0;
}
