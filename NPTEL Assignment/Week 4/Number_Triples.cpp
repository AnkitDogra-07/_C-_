#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = numeric_limits<int>::max();

int dijkstra(vector<vector<pair<int, int>>>& graph, int a, int b, int size){
    vector<int> dist(size, INF);
    dist[a] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({a, 0});

    while(!pq.empty()){
        int u = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        for(auto it: graph[u]){
            int v = it.first;
            int wt = it.second;

            if(d + wt < dist[v]){
                dist[v] = dist[u] + wt;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist[b];
}

int main() {
    int M, A, B, u, w, v;

    cin >> M >> A >> B;

    int N = 0;

    vector<vector<int>> edges;

    for(int i=0; i<M; i++){
        cin >> u >> w >> v;
        edges.push_back({u, w, v});
        N = max(N, max(u,v));
    }

    vector<vector<pair<int, int>>> chain(N+1);
    for(int i=0; i<M; i++){
        int u = edges[i][0];
        int v = edges[i][2];
        int wt = edges[i][1];

        chain[u].push_back({v, wt});
        chain[v].push_back({u, wt});
    }

    int ans = dijkstra(chain, A, B, N);

    if(ans != INF){
        cout << "YES" << endl << ans;
    }

    else{
        cout << "NO" << endl;
    }

    return 0;
}