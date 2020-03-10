#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Node {
private:
	map<char, Node*> children;
	bool completeWord;
public:
	Node(bool c);
	void insert(Node* root, string s);
};

Node::Node(bool c) {
	completeWord = c;
}

void Node::insert(Node* root, string s) {
	for(auto it = s.begin(); it != s.end(); ++it) {
		if(!root->children.count(*it)) {
			Node* n;
			if(it != s.end() - 1) {
				n = new Node(false);
			}
			else {
				n = new Node(true);
			}
			root->children.insert(pair<char, Node*>(*it,n));
		}
		else {
			root = (root->children)[*it];
		}
	}
}

int main() {
	Node* root = new Node(false);
	(*root).insert(root, string("abc"));
	return 0;
}


