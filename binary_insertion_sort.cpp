#include <iostream>
#include <vector>

template <typename Comparable>
int binary_search(std::vector<Comparable> v, Comparable k, int max, int min) {
    if(max <= min) 
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
  for(int i = 1; i < v.size(); ++i) {
    int  j = i - 1;
    Comparable tmp = std::move(v[i]);
    int l = binary_search(v, tmp, j, 0);
    while(j >= l) {
      v[j + 1] = std::move(v[j]);
      --j;
    }
    v[l] = std::move(tmp);
  }
  return v;
}

int main() {
  std::vector<double> v{4., 3., 2.};
  for(double i : binary_insertion_sort(v)) std::cout << i << " ";
  return 0;
}
