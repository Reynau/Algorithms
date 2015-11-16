#include <vector>
#include "Utilities.cpp"

void sort(vector<int>& v, int l, int center, int r) {
  int n = r-l+1;
  vector<int> aux(n);
  int index = 0;

  int firstPoint = l;
  int secondPoint = center+1;

  while(firstPoint <= center and secondPoint <= r) {
    if(v[firstPoint] <= v[secondPoint]) {
      aux[index] = v[firstPoint];
      ++firstPoint;
    }
    else {
      aux[index] = v[secondPoint];
      ++secondPoint;
    }
    ++index;
  }

  for(firstPoint; firstPoint <= center; ++firstPoint) {
    aux[index] = v[firstPoint];
    ++index;
  }
  for(secondPoint; secondPoint <= r; ++secondPoint) {
    aux[index] = v[secondPoint];
    ++index;
  }

  for(int i=0; i < n; ++i) {
    v[l] = aux[i];
    ++l;
  }
}

void mergeSort(vector<int>& v, int l, int r) {
  if(r > l) {
    int average = (l+r)/2;
    mergeSort(v, l, average);
    mergeSort(v, average+1, r);
    sort(v, l, average, r);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);

  readVector(v);
  mergeSort(v, 0, n-1);
  writeVector(v);
}
