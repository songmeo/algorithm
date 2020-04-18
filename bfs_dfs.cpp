#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;

/*
 * bfs on a binary tree is like level order, dfs is like preorder
 * bfs uses queue and dfs uses stack
 */

class Graph {
private:
	int vertices;
	list<int> *adj;
public:
	Graph(int i);
	void addEdge(int v, int w);
	void BFS(int s);
	void DFS(int s);
};

Graph::Graph(int i) {
	vertices = i;
	adj = new list<int>[i];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) { //s is starting vertice
	bool visited[vertices] = { false }; // mark all vertices as not visited
	queue<int> q; //a queue for exploration
	visited[s] = true; //mark s as visited node
	q.push(s); //enqueue s
	list<int>::iterator i;
	while(!q.empty()) {
		s = q.front();
		cout << s << " ";
		q.pop(); //remove the first element
		for(i = adj[s].begin(); i != adj[s].end(); ++i) {
			if(!visited[*i]) {
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

void Graph::DFS(int s) {
	bool visited[vertices] = { false };
	stack<int> st;
	//visited[s] = true;
	//cout << s << " ";
	st.push(s);
	while(!st.empty()) {
		s = st.top();
		st.pop();
		if(!visited[s]) {
			visited[s] = true;
			cout << s << " ";
			for(list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
				if(!visited[*i]) {
					st.push(*i);
				}
			}
		}
	}
}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 2);
	g.DFS(2);
	return 0;
}
