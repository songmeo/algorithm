#include <iostream>
#include <vector>

template <typename Comparable>
int binary_search(std::vector<Comparable> v, Comparable k, int max, int min) {
    if(max == min) 
      return (k > v[min])?(min + 1):min;
    int mid = (max + min) / 2;
    if(k == v[mid])
      return mid;
    else if(k < v[mid])
      return binary_search(v, k, mid - 1, min);
    else
      return binary_search(v, k, max, mid + 1);
}

template <typename Comparable>
std::vector<Comparable> binary_insertion_sort(std::vector<Comparable> v) {
  for(int i = 0; i < v.size(); ++i) {
    Comparable tmp = std::move(v[i + 1]);
    int l = binary_search(v, tmp, i, 0);
    for(int j = i; j >= l; --j) {
      v[j + 1] = std::move(v[j]);
    }
    v[l] = std::move(tmp);
  }
  return v;
}

int main() {
  std::vector<int> v{200, 0, 9, 10, 500, 300};
  for(int i : binary_insertion_sort(v)) std::cout << i << " ";
  return 0;
}
