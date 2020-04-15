#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
 * using the maximum subarray problem 
 */

class Solution {
public:
	int maxSubArray(vector<int> v) {
		int ans = INT_MIN;
		int sum = 0;
		for(int i : v) {
			sum += i;
			ans = max(ans, sum);
			sum = max(sum, 0);
		}
		return ans;
	}
};


int main() {
	vector<int> v ={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v1 = {-1};
	Solution s;
	cout << s.maxSubArray(v1);
	return 0;
}

