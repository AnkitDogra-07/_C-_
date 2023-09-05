#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
  int weight;
  int profit;
};

static bool cmp(struct Item a,  struct Item b){
  double r1 = static_cast<double>(a.profit) / static_cast<double>(a.weight);
  double r2 = static_cast<double>(b.profit) / static_cast<double>(b.weight);

  return r1>r2;
}

void fractional_knapSack(int capacity, vector<Item>& items){
  cout << "\n\n";
  int n = items.size();
  
  sort(items.begin(), items.end(), cmp);
  double ans = 0.0;  

  for(int i=0; i<n; i++){
    if(items[i].weight <= capacity){
      capacity -= items[i].weight;
      ans += items[i].profit;
      
      cout << "Item " << i+1 << " has been added to the sack." << endl << "Remaining Weight: " << static_cast<double>(capacity)<< endl << "Current Profit: " << ans << endl << endl; 
    }

    else{
      ans += items[i].profit * (static_cast<double>(capacity) / static_cast<double>(items[i].weight));
      cout << "Item " << i+1 << " has been added to the sack." << endl << "Remaining Weight: " << 0 << endl << "Current Profit: " << ans << endl; 	
      break;
    }
  } 
} 

int main(){
  int n, capacity;

  cout << "Enter number of Items: ";
  cin >> n;

  vector<Item> items(n);

  for(int i = 0; i<n; i++){
    cout << "Enter Weight & Profit of Item " << i+1 << " respectively : ";
    cin >> items[i].weight >> items[i].profit;
  }

  cout << "Enter maximum capacity of the KnapSack: ";
  cin >> capacity;

  fractional_knapSack(capacity, items);
}
