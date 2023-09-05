#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
  int weight;
  int profit;
};

static bool cmp(struct Item a,  struct Item b){
  double r1 = (double)a.profit / (double)a.weight;
  double r2 = (double)b.profit / (double)b.weight;

  return r1>r2;
}

double fractional_knapSack(int capacity, vector<Item>& items){
  int n = items.size();
  
  sort(items.begin(), items.end(), cmp);
  double ans = 0.0;  

  for(int i=0; i<n; i++){
    if(items[i].weight <= capacity){
      capacity -= items[i].weight;
      ans += items[i].profit;
    }

    else{
      ans += items[i].profit * ((double)capacity / (double)items[i].weight);
      break;
    }
  }

  return ans;
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

  double ans = fractional_knapSack(capacity, items);

  cout << "Maximum Profit: " << ans << endl;
}
