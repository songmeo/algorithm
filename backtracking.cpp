/*
 * using n-queen problem
 * return number of solutions
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 8
using namespace std;

int ans = 0;
void printSolution(int board[N][N]) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(int board[N][N], int row, int col) {
	//check upper rows
	for(int r = 0; r < row; r++) {
		if(board[r][col])
			return false;
	}
	//check upper diagonal on the left side
	for(int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
		if(board[r][c])
			return false;
	}
	//check upper diagonal on the right side
	for(int r = row, c = col; r >= 0 && c < N; r--, c++) {
		if(board[r][c])
			return false;
	}
	return true;
}

//find a place for a queen on each row
void solveNQ(int board[N][N], int row) {
	if(row == N) {
		ans++;
		printSolution(board);
	}
	for(int i = 0; i < N; i++) {
		if(isSafe(board, row, i)) {
			board[row][i] = 1;
			solveNQ(board, row + 1);
			board[row][i] = 0;
		}
	}
}

int main() {
	int board[N][N] = {0};
	solveNQ(board,0);
	cout << ans;
	return 0;
}
