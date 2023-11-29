class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int index){
        if (index == word.size()) {
            return true;  // The entire word is found
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;  // Out of bounds or mismatched character
        }

        char temp = board[row][col];
        board[row][col] = ' ';  // Mark the cell as visited

        // Explore adjacent cells
        if (helper(board, word, row + 1, col, index + 1) ||
            helper(board, word, row - 1, col, index + 1) ||
            helper(board, word, row, col + 1, index + 1) ||
            helper(board, word, row, col - 1, index + 1)) {
            return true;
        }

        board[row][col] = temp;  // Backtrack: restore the original value
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;    
    }
};