#include <iostream>
#include <vector>
using namespace std;

/*
 * merge sort using divide and conquer
 */
void merge(vector<int>& v, int lo, int mid, int hi) {
	vector<int> left(v.begin() + lo, v.begin() + mid);
	vector<int> right(v.begin() + mid + 1, v.begin() + hi);
	int l = 0, r = 0, i = 0;
	while(l < left.size() && r < right.size()) {
		if(left[l] < right[r]) {
			v[i++] = left[l++];
		}
		else {
			v[i++] = right[r++];
		}
	}
	for(; l < left.size(); l++) {
		v[i++] = left[l];
	}
	for(; r < right.size(); r++) {
		v[i++] = right[r];
	}
}

void mergesort(vector<int>& v, int l, int h) {
	if(l < h) {
		int mid = (l + h) / 2;
		mergesort(v, l, mid);
		mergesort(v, mid + 1, h);
		merge(v, l, mid, h);
	}
}

int main() {
	vector<int> v{1,2,6,3,9,8,7,10};
	mergesort(v, 0, v.size() - 1);
	for(int i : v)
		cout << i << " ";
	return 0;
}
