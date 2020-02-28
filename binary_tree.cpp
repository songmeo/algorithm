#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(int arr[], TreeNode* root, int i, int n) {
  if(i < n) {
    TreeNode* tmp = new TreeNode(arr[i]);
    root = tmp;
    root->left = insert(arr,root->left, 2*i + 1, n);
    root->right = insert(arr,root->right, 2*i + 2, n);
  }
  return root;
}

void printNode(TreeNode* root) {
  if(root != NULL) {
    printNode(root->left);
    cout << root->val << " ";
    printNode(root->right);
  }
}

int main() {
	int arr[] = {1,2,2,3,4,4,3};
	TreeNode* root = insert(arr, root, 0, sizeof(arr)/sizeof(arr[0]));
	printNode(root);
	return 0;
}
