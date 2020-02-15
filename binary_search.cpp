#include <iostream>
#include <vector>

template <typename Comparable>
int binary_search(std::vector<Comparable> v, Comparable k) {
  int min = 0, max = v.size() - 1, mid;
  while(v[min] <= v[max]) {
    mid = (max + min) / 2;
    if(k == v[mid]) 
      return mid; 
    else if(k < v[mid])
      max = mid - 1;
    else
      min = mid + 1;      
  }
  return -1;
}

int main() {
  std::vector<int> v{200, 0, 9, 10, 500, 300};
  std::cout << binary_search(v, 9) << std::endl;
  return 0;
}
