#include <iostream>
#include <vector>

/*
the idea is choosing a pivot, dividing into smaller than pivot and larger than pivot group,
doing the same with those 2 groups until group element become 0.
The first replacement to the real vector starts when smaller group has only 1 element left, which
is also the smallest item. It is then placed to the beginning of the vector, continuing with
same and larger groups. Because we know how many elements actually smaller and the same with pivot
we can place the elements in the right place without having to know those before it!
It's like swapping places between smaller and larger groups.
*/
template <typename Comparable>
void quick_sort(std::vector<Comparable> &v) {
  if(v.size() > 0) {
    std::vector<Comparable> smaller;
    std::vector<Comparable> same;
    std::vector<Comparable> larger;
    Comparable pivot = v[v.size()/2];
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
