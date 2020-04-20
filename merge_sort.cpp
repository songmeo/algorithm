#include <iostream>
#include <vector>
using namespace std;

void mergesort(int l, int h) {
	int l = 0, h = v.size() - 1;
	if(l < h) {
		int mid = (l + h) / 2;
		mergesort(l,h);
	}
}

int main() {
	vector<int> v{1,2,6,3,9,8,7};
	mergesort(v);
	for(int i : v)
		cout << i << " ";
	return 0;
}
