#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, l, d, i = 0;
        cin >> n >> k >> l;
        priority_queue<int> p;
        
        for (int i = 0; i < n; i++) {
            cin >> d;
            p.push(d);
        }

        vector<int> total_deliciousness(k, 0);

        while (!p.empty()) {
            total_deliciousness[i] += p.top();
            p.pop();
            i = (i + 1) % k;
        }

        cout << total_deliciousness[l-1] << endl; // Adjust for 1-based indexing
    }
    return 0;
}
