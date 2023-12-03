class Solution {
public:
void DFS(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
            return;

        // Mark the current 'O' as escaped
        board[i][j] = 'E';

        // DFS in all 4 directions
        DFS(board, i + 1, j);
        DFS(board, i, j - 1);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
    }

       void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        int rows = board.size();
        int cols = board[0].size();

        // DFS to mark 'O's connected to the border as 'E' (escaped)
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0);
            if (board[i][cols - 1] == 'O')
                DFS(board, i, cols - 1);
        }

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O')
                DFS(board, 0, j);
            if (board[rows - 1][j] == 'O')
                DFS(board, rows - 1, j);
        }

        // Flip remaining 'O's to 'X' and revert 'E' back to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }
};