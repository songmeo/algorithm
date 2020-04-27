#include <iostream>
#include <vector>
using namespace std;

/*
 * merge sort using divide and conquer
 */
void merge(vector<int>& v, vector<int>& ans, int lo, int mid, int hi) {
	int l = lo, r = mid + 1, k = lo;
	while(l <= mid && r <= hi) {
		if(v[l] <= v[r]) {
			ans[k++] = v[l++];
		}
		else {
			ans[k++] = v[r++];
		}
	}
	while(r <= hi) {
		ans[k++] = v[r++];
	}
	while(l <= mid) {
		ans[k++] = v[l++];
	}
}

void mergesort(vector<int>& v, vector<int>& ans, int l, int h) {
	if(l < h) {
		int mid = (l + h) / 2;
		mergesort(v, ans, l, mid);
		mergesort(v, ans, mid + 1, h);
		merge(v, ans, l, mid, h);
	}
}



int main() {
	vector<int> v{1,2,6,3,9,8,7,10};
	vector<int> ans(v.size());
	mergesort(v, ans, 0, v.size() - 1);
	for(int i : ans)
		cout << i << " ";
	return 0;
}
