#include <iostream>
#include <vector>

/*
* Choosing a pivot, iterating through the list and putting elements to lists regarding they are smaller,larger or same with pivot.
* Repeating this process with smaller and larger lists until there is no more elements to put into lists.
* 
* Time: 
* 	Dividing elements int lists costs n, the number of operations h is log(n) because n / 2^h = 1  
* 	worst: O(n^2) //the partition always happens at the beginning of the list so n -> n - 1 -> n - 2... so n(n + 1)/2 = n^2
* 	best:  Ω(n log(n)) //the pivot is the median
* 	average: Θ(n log(n))
* Space:
* 	O(log(n))
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
