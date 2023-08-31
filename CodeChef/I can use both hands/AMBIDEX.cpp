#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    string cmp = "codechef";
    unordered_map<char, vector<int>> map;
    int v = 0;
    string S;
    for (const auto& x : cmp) {
        map[x].push_back(v);
        v++;
    }

    int t;
    cin >> t;

    while (t--) {
        vector<bool> used(8, false); 
        string s(S.length(), ' ');
        cin >> S;
        sort(S.begin(), S.end());

        for (const char& x : S) {
            if (map.find(x) != map.end()) {
                for (const auto& i : map[x]) {
                    int pos = (i + 1) % 8;
                    while (used[pos]) {
                        pos = (pos + 1) % 8;
                    }
                    s[pos] = x;
                    used[pos] = true;
                    cout << "map" << endl;
                }
            }

            else {
                vector<int> available_positions;
                for (int i = 0; i < 8; i++) {
                    if (!used[i]) {
                        available_positions.push_back(i);
                    }
                    cout << "available positions" << endl;
                }

                if (!available_positions.empty()) {
                    // Generate a random index from the available positions
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<int> dist(0, available_positions.size() - 1);
                    int random_index = dist(gen);

                    // Place x at the randomly selected position
                    int j = available_positions[random_index];
                    s[j] = x;
                    used[j] = true;
                    cout << x << endl;
                }
            }
            cout << "outer" << endl;
        }

        cout << s << endl;
    }
    return 0;
}
