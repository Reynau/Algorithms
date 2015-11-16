#include <vector>
#include "Utilities.cpp"

int splitArray(vector<int>&v, int l, int r) {
  int pivot = r;
  int leftInd = l;
  while(leftInd < pivot) {
    if(v[leftInd] > v[pivot]) {
      swap(v, leftInd, pivot-1);
      swap(v, pivot-1, pivot);
      if(pivot>0) --pivot;
    }
    else ++leftInd;
  }
  return pivot;
}

void quickSort(vector<int>& v, int l, int r) {
  if(r > l) {
    int pivot = splitArray(v, l, r);
    quickSort(v, l, pivot-1);
    quickSort(v, pivot+1, r);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  
  readVector(v);
  quickSort(v, 0, n-1);
  writeVector(v);
}