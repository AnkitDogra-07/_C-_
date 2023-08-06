#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> five_way_merge(vector<vector<int>>& zone_lists) {
    unordered_map<int, int> candidate_count;
    vector<int> elected_candidates;

    for (int i = 0; i < 5; ++i) {
        for (int candidate : zone_lists[i]) {
            candidate_count[candidate]++;
            if (candidate_count[candidate] >= 3) {
                elected_candidates.push_back(candidate);
            }
        }
    }

    sort(elected_candidates.begin(), elected_candidates.end());
    elected_candidates.erase(unique(elected_candidates.begin(), elected_candidates.end()), elected_candidates.end());
    return elected_candidates;
}

int main() {
    vector<int> N(5);
    vector<vector<int>> zone_lists(5);

    for (int i = 0; i < 5; ++i) {
        cin >> N[i];
        zone_lists[i].resize(N[i]);

        for (int j = 0; j < N[i]; ++j) {
            cin >> zone_lists[i][j];
        }

        sort(zone_lists[i].begin(), zone_lists[i].end());
    }

    vector<int> elected_candidates = five_way_merge(zone_lists);
    cout << elected_candidates.size() << endl;

    return 0;
}
