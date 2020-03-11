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
	root = new Node();
	root->completeWord = false;
}

void Trie::insert(string s) {
	Node* p = root;
	for(char c : s) {
		auto m = p->children;
		if(!m.count(c)) {
			Node* n = new Node();
			m.insert(pair<char, Node*>(c,n));
		}
		else
			p = m[c];
	}
	p->completeWord = true;
}

int main() {
	Trie* t = new Trie();
	t->insert("abc");
	t->insert("adf");
	return 0;
}


