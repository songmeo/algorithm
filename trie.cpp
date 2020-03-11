#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
	unordered_map<char, Node*> children;
	bool completeWord;
};

class Trie {
private:
	Node* root;
public:
	Trie();
	void insert(string s);
	bool prefixSearch(string s); //if a prefix exists
	bool wordSearch(string s); //if whole word exists
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

bool Trie::prefixSearch(string s) {
	Node* p = root;
	for(char c : s) {
		auto m = p->children;
		if(m.count(c))
			p = m[c];
		else
			return false;			
	}
	return true;
}

bool Trie::wordSearch(string s) {
	Node* p = root;
	for(char c : s) {
		auto m = p->children;
		if(m.count(c))
			p = m[c];
		else
			return false;
	}
	return p->completeWord;
}

int main() {
	Trie* t = new Trie();
	string arr[] = {"abc", "abcd", "lmn", "edf"};
	for(string s : arr) 
		t->insert(s);
	cout << t->prefixSearch("ab");
	return 0;
}


