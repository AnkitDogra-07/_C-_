#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// **Iteration - 1**
// In this iteration, you used a five-way merge approach to find elected candidates.


/*-----------------------------------------------------------------------------------------------------------------------------------------
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
}*/



// **Iteration-2**
// In this iteration, you simplified the code by using separate variables for the counts of candidates in each zone.
/*
int main() {
    int N1, N2, N3, N4, N5;
    cin >> N1 >> N2 >> N3 >> N4 >> N5;

    vector<vector<int>> candidateLists = {
        vector<int>(N1),
        vector<int>(N2),
        vector<int>(N3),
        vector<int>(N4),
        vector<int>(N5)
    };

    // Input the candidate lists from each zone
    for (int i = 0; i < N1; ++i) cin >> candidateLists[0][i];
    for (int i = 0; i < N2; ++i) cin >> candidateLists[1][i];
    for (int i = 0; i < N3; ++i) cin >> candidateLists[2][i];
    for (int i = 0; i < N4; ++i) cin >> candidateLists[3][i];
    for (int i = 0; i < N5; ++i) cin >> candidateLists[4][i];

    // Sort each candidate list
    for (int i = 0; i < 5; ++i) {
        sort(candidateLists[i].begin(), candidateLists[i].end());
    }

    // Merge the sorted lists into one sorted list
    vector<int> mergedList;
    for (int i = 0; i < 5; ++i) {
        mergedList.insert(mergedList.end(), candidateLists[i].begin(), candidateLists[i].end());
    }
    sort(mergedList.begin(), mergedList.end());

    // Count how many times each candidate appears in the merged list
    unordered_map<int, int> candidateCount;
    for (int candidate : mergedList) {
        candidateCount[candidate]++;
    }

    // Count the number of candidates elected to the Council
    int electedCandidates = 0;
    for (const auto& candidate : candidateCount) {
        if (candidate.second >= 3) {
            electedCandidates++;
        }
    }

    // Output the result without the newline character
    cout << electedCandidates;

    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------
*/

// **Iteration-3**
// In this iteration, you further simplified the code by directly counting candidates in a single unordered_map.
int main(){
    int n1, n2, n3, n4, n5;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    unordered_map <int, int> candidate_list;
    int candidate;

    for(int i = 0; i < n1 + n2 + n3 + n4 + n5; i++){
        cin >> candidate;
        candidate_list[candidate]++;
    }

    int cnt = 0;

    for(const auto& x: candidate_list){
        if(x.second >= 3){
            cnt++;
        }
    }

    cout << cnt;
}
