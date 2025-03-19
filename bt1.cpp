#include<iostream>
using namespace std;


void towerofHanoi(int n, char from_rod, char to_rod, char aux_rod) {
	if (n == 1) {
		cout << " Move disk 1 from " << from_rod << " to " << to_rod << endl;
		return;
	}towerofHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
	towerofHanoi(n - 1, aux_rod, to_rod, from_rod);
}

bool isSort(int a[], int n) {
	if (n == 1 || n == 0) return true;
	if (a[0] > a[1]) return false;
	return isSort(a + 1, n - 1);
}

const int N = 8; // N-Queens size
int board[N][N] = { 0 }; // 8x8 Chessboard
int solutions = 0; // Count valid solutions

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false; // Check column

        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
            return false; // Check left diagonal

        if (col + (row - i) < N && board[i][col + (row - i)] == 1)
            return false; // Check right diagonal
    }
    return true;
}

// Backtracking function to place queens
void solveNQueens(int row)
{
    if (row == N)
    { // All queens placed successfully
        solutions++;
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1; // Place queen
            solveNQueens(row + 1); // Recur for next row
            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    solveNQueens(0);
    towerofHanoi(4, 'A', 'B', 'C');
    cout << solutions << endl;
}