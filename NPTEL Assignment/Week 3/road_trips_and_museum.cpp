#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Depth-First Search (DFS) function to explore cities and calculate museums to visit.
int dfs(vector<vector<int>>& direct, vector<int>& visited, vector<int>& museum, int node, int ans) {
    visited[node] = 1;

    // Add the number of museums in the current city to ans.
    ans += museum[node];

    for (int i : direct[node]) {
        if (visited[i] == 0) {
            ans = dfs(direct, visited, museum, i, ans);
        }
    }

    return ans;
}

int main() {
    int n, m, k, u, v, mu, cnt = 0, sum = 0;

    // Input the number of cities, roads, and vacation days.
    cin >> n >> m >> k;

    vector<vector<int>> direct(n + 1); // Direct routes between cities.
    vector<int> museum(n + 1); // Number of museums in each city.
    vector<int> total_museum; // Stores museums count reachable from each city.
    vector<int> visited(n + 1, 0); // Marks visited cities.

    // Input information about direct routes between cities.
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        direct[u].push_back(v);
        direct[v].push_back(u);
    }

    // Input the number of museums in each city.
    for (int i = 1; i <= n; i++) {
        cin >> mu;
        museum[i] = mu;
    }

    // Iterate through cities to calculate reachable museums.
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            cnt++; // Count unique cities visited.
            int rec = dfs(direct, visited, museum, i, 0);
            total_museum.push_back(rec);
        }
    }

    sort(total_museum.begin(), total_museum.end()); // Sort museums count.

    // When the number of cities to visit is less than the number of holidays.
    if (cnt < k) {
        cout << -1;
    }
    // When the number of cities to visit is equal to the number of holidays.
    else if (cnt == k) {
        for (int i : total_museum) {
            sum += i;
        }
        cout << sum;
    }
    // When the number of cities to visit is more than the number of holidays.
    else if (cnt > k) {
        int i = 0, j = total_museum.size() - 1;

        while (k) {
            sum += total_museum[j--];
            k--;

            if (k) {
                sum += total_museum[i++];
                k--;
            }
        }
        cout << sum;
    }

    return 0;
}
