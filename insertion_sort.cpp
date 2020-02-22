#include <iostream>
#include <vector>

/*
dividing vector into sorted and unsorted vectors. Moving elements from unsorted vector to sorted one
by comparing with every elements in the sorted group to find the correct place.
This process could be long and inefficient so binary insertion sort using binary search
to find out the correct place instead of going through the sorted vector everytime again.
*/
template <typename Comparable> 
std::vector<Comparable> insertion_sort(std::vector<Comparable> v) {
  for(int i = 1; i < v.size(); ++i) { //i = 0 is the first element in our sorted vector
    Comparable tmp = std::move(v[i]); //put the next value of unsorted vector into tmp for comparing with value in sorted sublist
    int j;
    for(j = i; j > 0 && tmp < v[j - 1]; --j) //while tmp is smaller than a value of sorted list, swap them 
      v[j]  = std::move(v[j - 1]); 
    v[j] = std::move(tmp); //at this point, j will be decreased to the position whose value is larger than tmp. If no such position found then j == i, and assign tmp back to v[j]  
  }
  return v;
}

int main() {
  std::vector<double> v{4.,3.,2.};
  for(double i : insertion_sort(v)) {
    std::cout << i << " ";
  }
  return 0;
}
