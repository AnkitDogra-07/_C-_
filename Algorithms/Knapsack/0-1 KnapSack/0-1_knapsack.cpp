// 0/1 KnapSack Problem

#include<iostream>
#include<vector>
using namespace std;

// Structure to represent an item with weight and profit
struct Item {
    int weight;
    int profit;
};

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(vector<Item>& items, int capacity) {
    int n = items.size();
    
    // Create a 2D array to store the maximum profit for each item and capacity
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Fill in the dp array using dynamic programming
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (items[i].weight <= w) {
                // If the current item can fit in the knapsack (weight <= remaining capacity),
                // choose the maximum profit between two options:
                // 1. Not including the current item (take the profit from the previous row).
                // 2. Including the current item (subtract its weight, find the profit with
                //    remaining capacity, and add the current item's profit).
                dp[i][w] = max(
                    (i > 0 ? dp[i - 1][w] : 0),
                    (i > 0 ? dp[i - 1][w - items[i].weight] : 0) + items[i].profit
                );
            } else {
                // If the current item's weight exceeds the remaining capacity, can't include it,
                // so simply take the maximum profit from the previous row.
                dp[i][w] = (i > 0 ? dp[i - 1][w] : 0);
            }
        }
    }
    
    // The final entry in dp represents the maximum profit achievable with all items and the given capacity.
    return dp[n - 1][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    // Input weights and profits for each item
    for (int i = 0; i < n; i++) {
        cout << "Enter Weight & Profit of Item " << i + 1 << " : ";
        cin >> items[i].weight >> items[i].profit;
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    // Call the knapSack function to calculate the maximum profit
    int maxProfit = knapSack(items, capacity);
    cout << "Maximum Profit: " << maxProfit << endl;
}

