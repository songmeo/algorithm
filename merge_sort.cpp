#include <iostream>
#include <vector>
using namespace std;

/*
 * merge sort using divide and conquer
 */
void merge(vector<int>& v, vector<int>& left, vector<int>& right) {
	int i = 0, l = 0, r = 0;
	while(l < left.size() && r < right.size()) {
		if(left[l] < right[r])
			v[i++] = left[l++];
		else
			v[i++] = right[r++];
	}
	for(; l < (int) left.size(); l++) {
		v[i++] = left[l];
	}
	for(; r < (int) right.size(); r++) {
		v[i++] = right[r];
	}
}

vector<int> mergesort(vector<int>& v, int l, int h) {
	if(l < h) {
		int mid = (l + h) / 2;
		vector<int> left = mergesort(v, l, mid);
		vector<int> right = mergesort(v, mid + 1, h);
		merge(v, left, right);
	}
	return v;
}

int main() {
	vector<int> v{1,2,6,3,9,8,7};
	for(int i : mergesort(v, 0, v.size() - 1))
		cout << i << " ";
	return 0;
}
