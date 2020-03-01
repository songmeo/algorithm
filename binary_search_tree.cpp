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
	TreeNode* search(int i);
	void destroy();
	void preorder_print();
private:
	void insert(int i, TreeNode* &root);
	void preorder_print(TreeNode* n);
	void destroy(TreeNode* n);
	TreeNode* root;
};

bst::bst() {
	root = NULL;
}

bst::~bst() {
	destroy();
}

void bst::insert(int i) {
	insert(i, root);
}

void bst::insert(int i, TreeNode* &node) {
	TreeNode* tmp = new TreeNode(i);
	if(!node)
		node = tmp;
	else if(tmp->val < node->val)
		insert(i,node->left);
	else if(tmp->val > node->val)
		insert(i,node->right);
}

void bst::preorder_print() {
	preorder_print(root);
}

void bst::preorder_print(TreeNode* node) {
	TreeNode* tmp = node;
	if(tmp) {
		cout << node->val << " ";
		preorder_print(node->left);
		preorder_print(node->right);
	}
}

void bst::destroy() {
	destroy(root);
}

void bst::destroy(TreeNode* node) {
	if(node) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

int main() {
	int arr[] = {10,6,14,5,8,11,18};
	bst* t = new bst();
	for(int i : arr) t->insert(i);
	t->preorder_print();
	t->destroy();
	return 0;
}

