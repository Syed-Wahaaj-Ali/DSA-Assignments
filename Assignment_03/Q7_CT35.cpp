/*
Assignment #3
Question 7:
Solve the classic N-Queens problem using recursion and backtracking. Place n queens on an n
x n chessboard such that no two queens attack each other. Print all possible solutions.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
   Name: Syed Wahaaj Ali
   Roll No: CT-24035
   Section A - CSIT
*/

bool isSafeToPlaceQueen(vector<string>& board, int row, int col,int n) {
	for(int j = 0 ; j < n; j++) if(board[row][j]=='Q') return false;
	for(int i = 0 ; i < n; i++) if(board[i][col]=='Q') return false;
	for(int i = row, j = col ; i >=0 && j>=0 ; i--,j--) if(board[i][j]=='Q') return false;
	for(int i = row, j = col ; i >=0 && j<n ; i--,j++) if(board[i][j]=='Q') return false;
	return true;
}

void helperFunc(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
	if (row == n) {
		ans.push_back(board);
		return;
	}

	for(int j = 0 ; j < n ; j++) {
		if(isSafeToPlaceQueen(board,row,j,n)) {
			board[row][j] = 'Q';
			helperFunc(board,row+1,n,ans);
			board[row][j] = '.';
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<string> board(n,string(n,'.'));
	vector<vector<string>> ans;
	helperFunc(board,0,n,ans);
	return ans;
}

int main() {
	
	int n;
	cout << "Enter the number of queens: ";
	cin >> n;
	
	vector<vector<string>> solutions = solveNQueens(n);
	cout << "\nTotal solutions: " << solutions.size() << endl << endl;
	for(int i = 0; i < solutions.size(); i++) {
		cout << "Solution " << i + 1 << ":\n";
		for(int j = 0; j < n; j++) {
			cout << solutions[i][j] << endl;
		}
		cout << endl;
	}
	
	return 0;
}
