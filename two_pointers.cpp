/*
 * given a sorted array, return the array contains only unique elements.
 * two pointer technique must be operated on sorted array.
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> uniqueElement(vector<int> v) {
		int j = 1;
		for(int i = 0; i < (int) v.size() - 2; i++) {
			if(v[i] != v[i+1])
				v[j++] = v[i+1];
		}
		v.erase(v.begin()+j, v.end());
		return v;
	}
};

int main() {
	vector<int> v{ 1,2,2,2,3,4,5,5 };
	Solution s;
	for(int i : s.uniqueElement(v)) {
		cout << i;
	}
	return 0;
}
