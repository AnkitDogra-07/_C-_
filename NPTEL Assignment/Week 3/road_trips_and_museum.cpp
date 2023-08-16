#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(vector<vector<int>>& direct, vector<int>& visited, vector<int>& museum, int node, int ans){
    visited[node] = 1;

    for(int i: direct[node]){
        if(visited[i] == 0){
            ans+=museum[i];
            ans = dfs(direct, visited, museum, i, ans);
        }
    }

    return ans;
}

int main(){
    int n, m, k, u, v, mu, cnt=0, sum=0;

    //Entering number of cities, number of roads and number of months respectively...
    cin >> n >> m >> k;

    vector<vector<int>> direct(n); vector<int> museum(n+1); vector<int> total_museum;
    vector<int> visited(n+1, 0);

    //Entering all the direct routes...
    for(int i=0; i<m; i++){
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

    if(cnt < k){
        cout << -1;
    }

    else if(cnt == k){
        for(int i:total_museum){
            sum+=i;
        }

        cout << sum;
    }

    else if(cnt > k){
        int start_sum = 0, end_sum = 0;
        int end = total_museum.size() - 1;
        sort(total_museum.begin(), total_museum.end());

        for(int i=0; i<k; i++){
            start_sum+=total_museum[i];
            end_sum+=total_museum[end];
            end--;
        }

        cout << start_sum + end_sum;
    }
    
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int dfs(vector<vector<int>>& direct, vector<int>& visited, vector<int>& museum, int node, int ans){
//     visited[node] = 1;

//     for(int i: direct[node]){
//         if(visited[i] == 0){
//             ans+=museum[i];
//             dfs(direct, visited, museum, i, ans);
//         }
//     }

//     return ans;
// }

// int main(){
//     int n, m, k, u, v, mu, cnt=0, sum=0;

//     // Entering number of cities, number of roads and number of months respectively...
//     cin >> n >> m >> k;

//     vector<vector<int>> direct(n + 1); 
//     vector<int> museum(n + 1);
//     vector<int> visited(n + 1, 0);
//     vector<int> total_museum;

//     // Entering all the direct routes...
//     for(int i=0; i<m; i++){
//         cin >> u >> v;
//         direct[u].push_back(v);
//         direct[v].push_back(u);
//     }

//     // Entering all the museums in ith city at the corresponding index position i...
//     for(int i=1; i<=n; i++){
//         cin >> mu;
//         museum[i] = mu;
//     }

//     for(int i=1; i<=n; i++){
//         if(visited[i] == 0){
//             cnt++;
//             int rec = dfs(direct, visited, museum, i, 0);
//             total_museum.push_back(rec);
//         }
//     }

//     if(cnt < k){
//         cout << -1;
//     }
//     else if(cnt == k){
//         for(int i: total_museum){
//             sum += i;
//         }
//         cout << sum;
//     }
//     else{
//         int start_sum = 0, end_sum = 0;
//         int end = total_museum.size() - 1;
//         sort(total_museum.begin(), total_museum.end());

//         for(int i=0; i<k; i++){
//             start_sum += total_museum[i];
//             end_sum += total_museum[end];
//             end--;
//         }

//         cout << start_sum + end_sum;
//     }
    
//     return 0;
// }
