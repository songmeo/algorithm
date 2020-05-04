/*
 * using n-queen problem
 * return number of solutions
 */
#include <iostream>
#include <vector>
using namespace std;

class pos {
public:
	int r, c;
	pos(int row, int col) { 
		r = row ; 
		c = col; 
	}
};

class Solution {
private:
	int ans = 0;
	int size;
public:
	Solution(int s) {
		size = s;
	}
	
	bool attacked(vector<pos> positions, pos p) {
		for(pos i : positions) {
			if(p.c == i.c || p.r == i.r || i.r + i.c == p.r + p.c || p.r - i.r == p.c - i.c) 
				return true;
		}
		return false;
	}
	
	bool solve(vector<pos> positions, int c) {
		//place a queen on each row
		for(int r = 0; r < size; r++) {
			pos* tmp = new pos(r,c);
			if(!attacked(positions, *tmp)) {
				if(solve(positions, c + 1)) {
					ans++;
					return true;
				}
			}
		}
		return false;
	}
	
	int n_queen() {
		vector<pos> positions;
		return ans;
	}
};

int main() {
	Solution s(4);
	cout << s.n_queen();
	return 0;
}
