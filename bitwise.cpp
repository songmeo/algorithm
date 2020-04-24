/*
 * using problem subset sum: given N numbers, check if
 * there is a subset of them with sum equal to target value
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool subsetsum(vector<int> &v, int k) {
		int n = v.size() - 1;
		for(int mask = 0; mask < (1 << n); mask++) {
			int sum = 0;
			for(int i = 0; i < n; i++) {
				if(mask & (1 << i))
					sum += v[i];
			}
			if(sum == k) return true;
		}
		return false;
	}
};

int main() {
	vector<int> v = { 0, 1, 2, 4, 5 };
	Solution s;
	cout << s.subsetsum(v, 5);
	return 0;
}
