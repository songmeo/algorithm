#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 
 * Edge list presentation:
 * space O(n) (number of edges)
 * finding all adjacent vertexes: time O(n) (linear search through edge list)
 * finding if 2 vertexes are connected: time O(n) (linear search through edge list)
 * Costly because number of edges could be close to quadratic number of vertices
*/
struct Edge {
	int startV; 
	int endV;
	int weight;
};

/*
 * Adjacency matrix
 * finding all adjacent vertexes: time O(n)
 * finding if 2 vertexes are connected: O(n)
 * Space is too costly O(v^2) (quadratic of number of vertexes)
*/

/*
 * Adjacency list
 * space complexity O(e) (number of edges)
 * finding all adjacent vertexes: time O(n)
 * finding if 2 vertexes are connected: 
*/
struct ajadencyList {
	vector<int> *al;
}

int main() {
}
