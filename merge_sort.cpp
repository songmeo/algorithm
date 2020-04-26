#include <iostream>
#include <vector>
using namespace std;

/*
 * merge sort using divide and conquer
 */
void merge(vector<int>& v, int l, int m, int h) {
	vector<int> L, R;
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = h - m;
}

void mergesort(vector<int>& v, int l, int h) {
	int l = 0, h = v.size() - 1;
	if(l < h) {
		int mid = (l + h) / 2;
		mergesort(v, l, mid);
		mergesort(v, mid + 1, h);
		merge(v, l, mid, h);
	}
}

int main() {
	vector<int> v{1,2,6,3,9,8,7};
	mergesort(v, l, h);
	for(int i : v)
		cout << i << " ";
	return 0;
}
