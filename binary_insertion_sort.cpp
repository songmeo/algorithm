#include <iostream>
#include <vector>

template <typename Comparable>
int binary_search(std::vector<Comparable> v, Comparable k) {
  int min = 0, max = v.size() - 1, mid;
  while(max > min) {
    mid = (max + min) / 2;
    if(k == v[mid]) 
      return mid; 
    else if(k < v[mid])
      max = mid - 1;
    else
      min = mid + 1;      
  }
  return (max + min)/2;
}

template <typename Comparable>
void binary_insertion_sort(std::vector<Comparable> v) {
  auto b = v.begin();
  for(int i = 1; i < v.size(); i++) {
    auto e = v.begin() + i - 1;
    std::vector<Comparable> tmp_vec(b,e);
    Comparable tmp = std::move(v[i]);
    int l = binary_search(tmp_vec, tmp);
    if(v[l] > tmp) v.insert(b + l, tmp);
    else v.insert(b + l + 1, tmp); 
  }
}

int main() {
  std::vector<int> v{200, 0, 9, 10, 500, 300};
  binary_insertion_sort(v);
  for(int i : v) std::cout << i << " ";
  //std::vector<int> v1{1,200};
  //std::cout << binary_search(v1,9) << std::endl;
  return 0;
}
