#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
	map<char, Node*> children;
	bool completeWord;
};

class Trie {
private:
	Node* root;
public:
	Trie();
	void insert(string s);
};

Trie::Trie() {
}

void Trie::insert(string s) {
	Node* p = root;
	for(auto it = s.begin(); it != s.end(); ++it) {
		if(!p->children.count(*it)) {
			Node* n = new Node();
			root->children.insert(pair<char, Node*>(*it,n));
		}
		else {
			p = p->children[*it];
		}
	}
}

int main() {
	Trie* t = new Trie();
	t->insert("abc");
	//t->insert("adf");
	return 0;
}


