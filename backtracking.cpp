/*
 * backtracking solution begins with an empty solution and extends it
 * step by step. The search recursively goes through all different ways
 * how a solution can be constructed.
 * 
 * using n-queen problem
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int n_queen(int n) {
		int solutions = 0;
		vector<vector<int>> v(n);
		return 1;
	}
};

int main() {
	Solution s;
	cout << s.n_queen(4);
	return 0;
}
