#include<iostream>
#include<vector>
using namespace std;

struct item{
 int weight;
 int profit;
};

int knapSack(vector<item>& items, int capacity){
  int n = items.size();
  vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
  
  for(int i=0; i<n; i++){
    for(int w=0; w<=capacity; w++){
      if(dp[i] <= w){
        dp[i][w] = max(
          (i>0 ? dp[i-1][w] : 0),
          (i>0 ? dp[i-1][w - items[i].weight] : 0) + items[i].profit
        );  
      }
    }
  }
}
