#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

long long shortestPathToKillDragons(vector<pair<int, int>>& dragonPositions, int K) {
    int D = dragonPositions.size(); // Number of dragons in the grid

    // Create a 2D array mindist to store minimum distances
    vector<vector<long long>> mindist(D + 1, vector<long long>(K + 1, LLONG_MAX));

    // Initialize the mindist array
    mindist[0][0] = 0;

    // Iterate through the dragons
    for (int i = 1; i <= D; ++i) {
        // Iterate through the number of dragons to kill
        for (int j = 1; j <= K; ++j) {
            // Initialize mindist[i][j] to a large value
            mindist[i][j] = LLONG_MAX;

            // Iterate through previous dragons
            for (int k = 0; k < i; ++k) {
                // Calculate distance from previous dragon k to dragon i
                long long distance = abs(static_cast<long long>(dragonPositions[i - 1].first - dragonPositions[k].first)) +
                                    abs(static_cast<long long>(dragonPositions[i - 1].second - dragonPositions[k].second));

                // Update mindist[i][j] with the minimum distance
                mindist[i][j] = min(mindist[i][j], mindist[k][j - 1] + distance);
            }
        }
    }

    // Find the minimum distance among mindist[D][K]
    long long minDistance = LLONG_MAX;
    for (int i = 1; i <= D; ++i) {
        minDistance = min(minDistance, mindist[i][K]);
    }

    return minDistance;
}
    

int main() {
    int R, C, K, D; // Dimensions, dragons to kill
    cin >> R >> C >> K >> D;

    vector<pair<int, int>> dragonPositions(D); // Store dragon positions

    // Input dragon positions
    for (int i = 0; i < D; ++i) {
        int r, c;
        cin >> r >> c;
        dragonPositions[i] = make_pair(r, c);
    }

    int result = shortestPathToKillDragons(dragonPositions, K);
    cout << result << endl;

    return 0;
}
