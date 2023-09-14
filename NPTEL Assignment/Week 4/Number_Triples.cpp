#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Define INF as the maximum possible integer value
int INF = numeric_limits<int>::max();

// Dijkstra's algorithm to find the minimum value chain
int dijkstra(vector<vector<pair<int, int>>>& graph, int a, int b, int size) {
    // Initialize an array to store the minimum distances from vertex 'a' to all other vertices
    vector<int> dist(size, INF);
    dist[a] = 0; // Distance from 'a' to itself is 0

    // Create a priority queue to select the vertex with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({a, 0}); // Start from vertex 'a' with distance 0

    // Apply Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().first; // Get the vertex with the smallest distance
        int d = pq.top().second; // Get its distance
        pq.pop();

        // Iterate through the neighbors of vertex 'u'
        for (auto it : graph[u]) {
            int v = it.first; // Neighbor vertex
            int wt = it.second; // Weight of the edge from 'u' to 'v'

            // If a shorter path to 'v' through 'u' is found, update the distance
            if (d + wt < dist[v]) {
                dist[v] = d + wt;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist[b]; // Return the minimum distance from 'a' to 'b'
}

int main() {
    int M, A, B, u, w, v;

    cin >> M >> A >> B;

    int N = 0; // Initialize N to 0

    vector<vector<int>> edges; // Store the input edges

    // Read input triples and find the maximum vertex number 'N'
    for (int i = 0; i < M; i++) {
        cin >> u >> w >> v;
        edges.push_back({u, w, v});
        N = max(N, max(u, v));
    }

    // Create an adjacency list 'chain' to represent the graph
    vector<vector<pair<int, int>>> chain(N + 1);

    // Populate the adjacency list based on input edges
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][2];
        int wt = edges[i][1];

        chain[u].push_back({v, wt});
        chain[v].push_back({u, wt});
    }

    // Find the minimum value chain length using Dijkstra's algorithm
    int ans = dijkstra(chain, A, B, N);

    if (ans != INF) {
        cout << "YES" << endl << ans; // If a valid chain exists, print "YES" and the minimum value chain length
    } else {
        cout << "NO" << endl; // If no chain exists, print "NO"
    }

    return 0;
}
