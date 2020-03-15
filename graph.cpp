#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 
 * undirected weighted graph
 * edge list: space complexity O(n) (start and end vertexes are presented as reference to the vertext list
 * so the cost for every elements is the same)
 * finding all adjacent vertexes: time complexity O(n) (linear search through edge list for a certain vertex)
 * finding if 2 vertexes are connected: time complexity 0(n) (linear search through edge list)
*/
struct Edge {
	int startV; 
	int endV;
	int weight;
};


int main() {
	vector<Edge* > EdgeList;
}
