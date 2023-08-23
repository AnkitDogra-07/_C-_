#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Edge{
    int vertex;
    int weight;
};

int main(){
    int M, A, B, u, w, v;

    cin >> M >> A >> B;

    vector<vector<Edge>> chain;

    for(int i=0; i<M; i++){
        for(int j=0; j<3; j++){
           cin >>  u >> w >> v;
           chain[u].push_back({v, w});
           chain[v].push_back({u, w});
        }
        cout << endl;
    }

}