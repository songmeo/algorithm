/*
 * creating a random DAG
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
//maximum number of vertex for a sample random graph
#define max 20

bool checkAcyclic(int edge[][2], int ed, bool check[], int v) {
	int i;
	if(check[v] == true) //if the node is visited -> there is a cycle
		return false;
	else {
		check[v] = true;
		for(i = ed; i >= 0; i--) {
			if(edge[i][0] == v)
				return checkAcyclic(edge, ed, check, edge[i][1]);
		}
	}
	check[v] = false;
	if(i == 0)
		return true;
}

void GenerateRandomGraphs(int e) {
	int i, j, edge[e][2], count;
	bool c[21];
	i = 0;
	while(i < e) {
		edge[i][0] = rand()%max+1; //generate a random number between 1 and max
		edge[i][1] = rand()%max+1;
		
		for(j = 1; j <= 20; j++)
			check[j] = false;
		
		if(checkAcyclic(edge, i, check, edge[i][0]) == true)
			i++;
	}
}

int main() {
	cout << rand()%max+1;
	return 0;
}
