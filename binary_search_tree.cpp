/*
 * binary search tree has at most 2 nodes.
 * The left subtree has smaller values than the root node.
 * The right subtree has larger values than the root node.
 */
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class bst {
public:
	bst();
	~bst();
	void insert(int i);
	void remove(TreeNode* n);
	void printPreOrder();
private:
	void insert(int i, TreeNode* root);
}

void bst::insert(int i) {

}

void bst::insert(TreeNode* &root, TreeNode* tmp) {
	if(!root) root = tmp;
	else if(root->val < tmp->val)
		insert(root->left,tmp);
	else
		insert(root->right,tmp);
}

void printPreOrder(TreeNode* root) {
	TreeNode* tmp = root;
	if(tmp) {
		cout << root->val << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

int main() {
	int arr[] = {11,6,8,19,4,10,5,17,43,49,31};
	TreeNode* root = 0;
	for(int i : arr) {
		TreeNode* tmp = new TreeNode(i);
		insert(root, tmp);
	}
	printPreOrder(root);
	return 0;
}

