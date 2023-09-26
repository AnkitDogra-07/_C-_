#include <iostream>
#include <vector>
#include "../Boilerplate/swap.hpp"
using std::vector, std::cout, std::cin;

void heapify(vector<int>& heap, int n, int i){
  int parent = (i-1)/2;
  int left = (2*i) - 1;
  int right = (2*i) + 2;

  if(left < n && heap[left] > heap[parent]){
    parent = left;
  }

  if(right < n && heap[right] > heap[parent]){
    parent = right;
  }

  if(parent != i){
    swap(heap[parent], heap[i]);
    heapify(heap, n, parent);
  }
}

void build_heap(vector<int>& heap){
  int index_init = (heap.size()/2) - 1;

  for(int i= index_init; i>=0; i--){
    heapify(heap, heap.size(), i);
  }
}

int main(){
  int n, node;
  cout << "Enter size of heap : ";
  cin >> n;

  vector<int> heap(n);

  for(int i=0; i<n; i++){
    cin >> node;
    heap.push_back(node);
  }

  build_heap(heap);

  for(const int& x: heap){
    cout << x << "\t";
  }
}