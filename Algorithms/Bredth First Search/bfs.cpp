#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>

using  std::string, std::cout, std::cin, std::endl, std::vector, std::list, std::max;

struct Chain{
  int n1;
  int n2;
}; 

vector<vector<Chain>> adj_lst;

vector<int> bfs(int start_node, vector<bool>& visited, int max) {
    visited.resize(max + 1, false);
    list<int> q;
    vector<int> bfsTraversal;

    visited[start_node] = true;
    q.push_back(start_node);
    bfsTraversal.push_back(start_node);

    while (!q.empty()) {
        int s = q.front();
        q.pop_front();

        for (auto& x : adj_lst[s]) {
            int neighbor = (s == x.n1) ? x.n2 : x.n1;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push_back(neighbor);
                bfsTraversal.push_back(neighbor);
            }
        }
    }

  return bfsTraversal;
}

int main(){
  int n, m = -1;
  cout << "Enter size of tree:";
  cin >> n;

  cout << "Enter Nodes...\n";
  for(int i=0; i<n; i++){
    Chain chain;
    cin >> chain.n1 >> chain.n2;

    m = max(m, max(chain.n1, chain.n2));
    adj_lst.resize(m + 1);
    adj_lst[chain.n1].push_back(chain);
    adj_lst[chain.n2].push_back(chain);
  }

    int start_node;
    cout << "Enter the starting node: ";
    cin >> start_node;

    vector<bool> visited(m + 1, false); 
    vector<int> ans = bfs(start_node, visited, m);

    cout << "Following is the Breadth First Traversal from Node " << start_node << ": ";
      for(int node: ans){
        cout << node << " ";
      }
    cout << endl;

    return 0;
}
  
