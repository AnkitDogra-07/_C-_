#include <iostream>
#include <vector>
#include "../Boilerplate/swap.hpp"
using std::vector;

void heapify(vector<int>& heap, int i){
  int parent = (i-1)/2;
  
  if(heap[parent] > 0){
    if(heap[parent] < heap[i]){
      swap(heap[i], heap[parent]);

      heapify(heap, parent);   
    }
  }
}

void insert_node(vector<int>& heap, int node){
  vector<int> heap(heap.size() + 1);
  heap[heap.size() - 1] = node;
  heapify(heap, heap.size() - 1);
}

int main(){

}