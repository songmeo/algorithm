#include <iostream>
#include <vector>

template <typename Comparable> 
std::vector<Comparable> insertion_sort(std::vector<Comparable> v) {
  for(int i = 1; i < v.size(); ++i) { //i = 0 is our sorted sublist
    Comparable tmp = std::move(v[i]); //put the next value of unsorted sublist into tmp for comparing with value in sorted sublist
    int j;
    for(j = i; j > 0 && tmp < v[j - 1]; --j) //while tmp is smaller than a value of sorted list, swap them 
      v[j]  = std::move(v[j - 1]); 
    v[j] = std::move(tmp); //at this point, j will be decreased to the position whose value is larger than tmp. If no such position found then j == i, and assign tmp back to v[j]  
  }
  return v;
}

int main() {
  std::vector<int> v{0,1,2,5,4,3};
  for(int i : insertion_sort(v)) {
    std::cout << i << " ";
  }
  return 0;
}
