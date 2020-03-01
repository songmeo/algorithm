#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
  if(i < n) {
    TreeNode* tmp = new TreeNode(arr[i]);
    root = tmp;
    root->left = insertLevelOrder(arr,root->left, 2*i + 1, n);
    root->right = insertLevelOrder(arr,root->right, 2*i + 2, n);
  }
  return root;
}

//left right root
void printInOrder(TreeNode* root) {
  if(root != NULL) {
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
  }
}

//root left right
void printPreOrder(TreeNode* root) {
	if(root) {
		cout << root->val << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

//left right root
void printPostOrder(TreeNode* root) {
	if(root) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->val << " ";
	}
}

int main() {
	int arr[] = {1,2,2,3,4,4,3};
	TreeNode* root = insertLevelOrder(arr, root, 0, sizeof(arr)/sizeof(arr[0]));
	cout << "InOrder: ";
	printInOrder(root);
	cout << endl;
	cout << "PreOrder: ";
	printPreOrder(root);
	cout << endl;
	cout << "PostOrder: ";
	printPostOrder(root);
	return 0;
}
