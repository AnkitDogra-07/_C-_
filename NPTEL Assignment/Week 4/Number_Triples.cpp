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

void dijkstra(){

}

int main() {
    int M, A, B, u, w, v;

    cin >> M >> A >> B;

    unordered_map<int, vector<Edge>> chain;

    for(int i=0; i<M; i++){
        cin >> u >> w >> v;
        chain[u].push_back({v, w});
        chain[v].push_back({u, w});
    }

}


