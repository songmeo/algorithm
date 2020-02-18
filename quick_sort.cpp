#include <iostream>
#include <vector>

template <typename Comparable>
void quick_sort(std::vector<Comparable> &v) {
  Comparable pivot;
  if(v.size() > 0) {
    std::vector<Comparable> smaller;
    std::vector<Comparable> same;
    std::vector<Comparable> larger;
    pivot = v[v.size()/2];
    for(Comparable i : v) {
      if(i < pivot)
        smaller.push_back(std::move(i));
      else if(i > pivot)
        larger.push_back(std::move(i));
      else
        same.push_back(std::move(i));
    }
    quick_sort(smaller);
    quick_sort(larger);
    move(smaller.begin(), smaller.end(), v.begin());
    move(same.begin(), same.end(), v.begin() + smaller.size());
    move(larger.begin(), larger.end(), v.begin() + smaller.size() + same.size());
  }
}

int main() {
  std::vector<int> v{0,3,5,10,100,99};
  quick_sort(v);
  for(int i : v)
    std::cout << i << " ";
  return 0;
}
