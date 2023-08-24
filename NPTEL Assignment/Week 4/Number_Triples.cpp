#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
using namespace std;

struct Edge {
    int vertex;
    int weight;
};

int INF = numeric_limits<int>::max();

void dijkstra(unordered_map<int, vector<Edge>> graph, int a, int b, int size){
    vector<int> dist(size, INF);
    dist[a] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, a});

    while(!pq.empty()){
        
    }
}

int main() {
    int M, A, B, u, w, v;

    cin >> M >> A >> B;
    int unq_index = 0;

    int max = 0;

    unordered_map<int, vector<Edge>> chain;

    for(int i=0; i<M; i++){
        cin >> u >> w >> v;
        chain[u].push_back({v, w});
        chain[v].push_back({u, w});

        if(u > v && u > max){
            max = u;
        }

        if(v > u && v > max){
            max = v;
        }
    }

}


