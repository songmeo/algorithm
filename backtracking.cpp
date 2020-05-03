/*
 * using n-queen problem
 */
#include <iostream>
#include <vector>
using namespace std;

class pos {
	int x, y;
	pos(int x, int y) : x(x), y(y) {}
};

class Solution {
private:
	int size;
public:
	Solution(int s) {
		size = s;
	}
	
	bool attacked(vector<pos> positions, pos p) {
		for(pos i : positions) {
			if(p.x == i.x || p.y == i.y || i.x + i.y == p.x + p.y || p.x - i.x == p.y - i.y) 
				return true;
		}
		return false;
	}
	
	int n_queen {
		int ans = 0;
		vector<pos> positions;
		//place a queen on each row
		int r = 0, c = 0;
		if(p.x == i.x || p.y == i.y || i.x + i.y == p.x + p.y || p.x - i.x == p.y - i.y) 
				return true;
		else
			c++;
		return ans;
	}
};

int main() {
	Solution s(4);
	cout << s.n_queen;
	return 0;
}
