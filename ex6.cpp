#include <iostream>
#include<vector>
using namespace std;

int N = 8; 
vector<vector<int> > board;
int solutions = 0; 

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false; 
       if (col - (row - i) >= 0 && col - (row-i)<N&& board[i][col - (row - i)] == 1) return false; 
        if (col + (row - i) < N && col+(row-i)>=0 board[i][col + (row - i)] == 1) return false; 
    }
    return true;
}


void solveNQueens(int row) {
    if (row == N) { 
        solutions++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; 
            solveNQueens(row + 1); 
            board[row][col] = 0; 
        }
    }
}

int solve(int n){
	N=n;
	solutions=0;
	vector<int> temp(n,0);
	for(int i=0;i<n;i++){
		board.push_back(temp);
	}solveNQueens(0);
}

int main() {
	int n; cin>>n;
    solve(n);
    cout << "Total solutions: " << solutions << endl;
    return 0;
}

