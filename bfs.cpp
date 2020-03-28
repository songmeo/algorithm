#include <iostream>
#include <queue>
using namespace std;

//bfs on a binary tree is like level order, dfs is like preorder
class Graph {
private:
	int V;
	vector<list<int>> adj;
public:
	Graph(int v);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int v) {
	V = v;
	adj = new queue<int>[V];
}

struct Node {
	char data;
	Node* next;
	Node(char c): data(c), next(NULL) {}
}

int main() {
}
