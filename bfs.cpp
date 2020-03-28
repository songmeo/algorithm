#include <iostream>
#include <queue>
#include <list>
using namespace std;

//bfs on a binary tree is like level order, dfs is like preorder
class Graph {
private:
	int V;
	vector<list<int>> *adj;
public:
	Graph(int v);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int v) {
	V = v;
	adj = new queue<int>[V];
}

Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	vector<bool> visited(V);
	queue<int> q;
	visited[s] = true;
	queue.push(s);
}
