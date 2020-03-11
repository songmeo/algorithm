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
	void printAll(Node* tmp);
public:
	Trie();
	void insert(string s);
	bool prefixSearch(string s); //if a prefix exists
	bool wordSearch(string s); //if whole word exists
	void printAll();
};

Trie::Trie() {
	root = new Node();
	root->completeWord = false;
}

void Trie::insert(string s) {
	Node* p = root;
	for(char c : s) {
		auto &m = p->children;
		if(!(p->children).count(c)) {
			Node* n = new Node();
			m.insert(pair<char, Node*>(c,n));
		}
		p = m[c];
	}
	p->completeWord = true;
}

void Trie::printAll() {
	printAll(root);
}

void Trie::printAll(Node* tmp) {
	Node* t = tmp;
	auto m = t->children;
	if(!m.empty()){
		for(auto p : m) {
			cout << p.first << " ";
			printAll(p.second);	
		}
	}
}

bool Trie::prefixSearch(string s) {
	Node* p = root;
	size_t i;
	for(i = 0; i < s.length(); ++i) {
		auto m = p->children;
		if(m.count(s[i]))
			p = m[s[i]];
		else
			return false;			
	}
	return i == s.length() - 1;
}

bool Trie::wordSearch(string s) {
	Node* p = root;
	size_t i;
	for(i = 0; i < s.length(); ++i) {
		auto m = p->children;
		if(m.count(s[i]))
			p = m[s[i]];
		else {
			return false;	
		}		
	}
	
	return p->completeWord;
}

int main() {
	Trie* t = new Trie();
	string arr[] = {"abc", "abcd", "lmn", "edf"};
	for(string s : arr) 
		t->insert(s);
	t->printAll();
	cout << t->wordSearch("abcde");
	return 0;
}


