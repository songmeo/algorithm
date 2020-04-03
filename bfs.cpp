#include <iostream>
#include <queue>
#include <list>
using namespace std;

//bfs on a binary tree is like level order, dfs is like preorder
class Graph {
private:
	int vertices;
	list<int> *adj;
public:
	Graph(int i);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int i) {
	vertices = i;
	adj = new list<int>[i];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	bool visited[vertices] = { false }; // mark all vertices as not visited
	queue<int> q; //a queue for bfs
	visited[s] = true; //mark s as visited node
	q.push(s); //enqueue s
	list<int>::iterator i;
	while(!q.empty()) {
		s = q.front();
		cout << s << " ";
		q.pop();
		for(i = adj[s].begin(); i != adj[s].end(); ++i) {
			if(!visited[*i]) {
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.BFS(2);
	return 0;
}
