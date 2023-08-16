#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(vector<vector<int>>& direct, vector<int>& visited, vector<int>& museum, int node, int ans){
    visited[node] = 1;

    // Add the number of museums in the current node to ans
    ans += museum[node];

    for(int i : direct[node]){
        if(visited[i] == 0){
            ans = dfs(direct, visited, museum, i, ans);
        }
    }

    return ans;
}

int main(){
    int n, m, k, u, v, mu, cnt=0, sum=0;

    //Entering number of cities, number of roads and number of months respectively...
    cin >> n >> m >> k;

    vector<vector<int>> direct(n+1); vector<int> museum(n+1); vector<int> total_museum;
    vector<int> visited(n+1, 0);

    //Entering all the direct routes...
    for(int i=1; i<m+1; i++){
        cin >> u >> v;
        direct[u].push_back(v);
        direct[v].push_back(u);
    }

    //Entering all the musuem in ith city at the corresponding index position i...
    for(int i=1; i<n+1; i++){
        cin >> mu;
        museum[i] = mu;
    }

    for(int i=1; i<n+1; i++){
        if(visited[i] == 0){
            cnt++;
            int rec = dfs(direct, visited, museum, i, 0);
            total_museum.push_back(rec);
        }
    }

    sort(total_museum.begin(), total_museum.end());

    if(cnt < k){
        cout << -1;
    }

    else if(cnt == k){
        for(int i:total_museum){
            sum+=i;
        }

        cout << sum;
    }

    else if (cnt > k){
        int i=0, j=total_museum.size()-1;
    
        while(k){
            sum+=total_museum[j--];
            k--;

            if(k){
                sum+=total_museum[i++];
                k--;
            }
        }

        cout << sum;

    }
    
    return 0;
}
