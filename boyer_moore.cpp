/*
 * using majority element problem. Given an array
 * find the element that occurs more than n/2 times. 
 * Given that there is always a majority element.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int> v) {
		int candidate = 0, counter = 0;
		for(int i : v) {
			if(counter == 0) {
				candidate = i;
				counter++;
			}
			else if(i == candidate) {
				counter++;
			}
			else {
				counter--;
			}
		}
		return counter>0?candidate:-1;
	}
};

int main() {
	vector<int> v{ 3,2,3 };
	Solution s;
	cout << s.majorityElement(v);
	return 0;
}
