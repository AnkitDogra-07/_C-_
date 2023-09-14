#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Define a structure to represent items with weight and profit
struct Item {
  int weight;
  int profit;
};

// Define a comparison function for sorting items by their profit-weight ratios
static bool cmp(struct Item a,  struct Item b) {
  // Calculate profit-weight ratios for items a and b
  double r1 = static_cast<double>(a.profit) / static_cast<double>(a.weight);
  double r2 = static_cast<double>(b.profit) / static_cast<double>(b.weight);

  // Compare items based on their profit-weight ratios in descending order
  return r1 > r2;
}

// Function to solve the fractional knapsack problem
void fractional_knapSack(int capacity, vector<Item>& items) {
  cout << "\n\n";
  int n = items.size();
  
  // Sort the items in descending order of profit-weight ratios
  sort(items.begin(), items.end(), cmp);
  double ans = 0.0;  

  for(int i = 0; i < n; i++) {
    if(items[i].weight <= capacity) {
      // Add the entire item to the knapsack
      capacity -= items[i].weight;
      ans += items[i].profit;
      
      cout << "Item " << i+1 << " has been added to the sack." << endl
           << "Remaining Weight: " << static_cast<double>(capacity) << endl
           << "Current Profit: " << ans << endl << endl; 
    } else {
      // Add a fraction of the item to the knapsack
      ans += items[i].profit * (static_cast<double>(capacity) / static_cast<double>(items[i].weight));
      cout << "Item " << i+1 << " has been added to the sack." << endl
           << "Remaining Weight: " << 0 << endl
           << "Current Profit: " << ans << endl; 	
      break;
    }
  } 
} 

int main() {
  int n, capacity;

  // Input the number of items and maximum capacity of the knapsack
  cout << "Enter number of Items: ";
  cin >> n;

  vector<Item> items(n);

  // Input the weight and profit of each item
  for(int i = 0; i < n; i++) {
    cout << "Enter Weight & Profit of Item " << i+1 << " respectively : ";
    cin >> items[i].weight >> items[i].profit;
  }

  cout << "Enter maximum capacity of the KnapSack: ";
  cin >> capacity;

  // Solve the fractional knapsack problem
  fractional_knapSack(capacity, items);
}
