#include<iostream>
#include<vector>
using namespace std;

struct Item {
    int weight;
    int profit;
};

int knapSack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (items[i].weight <= w) {
                dp[i][w] = max(
                    (i > 0 ? dp[i - 1][w] : 0),
                    (i > 0 ? dp[i - 1][w - items[i].weight] : 0) + items[i].profit
                );
            } else {
                dp[i][w] = (i > 0 ? dp[i - 1][w] : 0);
            }
        }
    }
    return dp[n - 1][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Weight & Profit of Item " << i + 1 << " : ";
        cin >> items[i].weight >> items[i].profit;
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    int maxProfit = knapSack(items, capacity);
    cout << "Maximum Profit: " << maxProfit << endl;
}

