class Solution {
public:
void solveNQueensUtil(vector<string>& board, int row, int n,int &count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solveNQueensUtil(board, row + 1, n,count);
                board[row][col] = '.';  // Backtrack
            }
        }
    }

    bool isValid(const vector<string>& board, int row, int col, int n) {
        // Check if there is a queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check if there is a queen in the left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check if there is a queen in the right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
}
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count=0;
        solveNQueensUtil(board, 0, n,count);
        
        return count;
    }
};