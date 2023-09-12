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

void search(int curr_node, vector<bool>& visited, int max) {
    visited.resize(max + 1, false);
    list<int> q;

    visited[curr_node] = true;
    q.push_back(curr_node);

    while (!q.empty()) {
        int s = q.front();
        q.pop_front();

        for (auto& x : adj_lst[s]) {
            int neighbor = (s == x.n1) ? x.n2 : x.n1;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push_back(neighbor);
            }
        }
    }
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
    search(start_node, visited, m);

    cout << "Nodes reachable from node " << start_node << ": ";
    for (int i = 0; i <= m; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
  
