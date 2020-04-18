/*
 * using problem finding longest substring without repeating character
 */
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int longestSubstring(string s) {
		unordered_map<char,int> m;
		if(s.empty()) return 0;
		int ans = 1;
		for(int i = 0, j = 0; j < (int) s.size(); j++) {
			if(m.count(s[j])== 0) {
				m[s[j]] = j;	
			}
			else {
				i = max(i, m[s[j]] + 1);
				m[s[j]] = j;
			}
			ans = max(ans, j - i + 1);
		}
		return ans;
	}
};

int main() {
	string str = "tmmzuxt";
	Solution s;
	cout << s.longestSubstring(str);
	return 0;
}

