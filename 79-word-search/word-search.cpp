class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int index){
        if (index == word.size()) {
            return true;
        }

        // Check if the current indices are within bounds
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
            // Check if the current character matches the next character in the word
            if (board[row][col] == word[index]) {
                // Temporarily mark the current cell as visited
                char temp = board[row][col];
                board[row][col] = ' ';

                // Recursively check adjacent cells
                if (helper(board, word, row + 1, col, index + 1) ||
                    helper(board, word, row - 1, col, index + 1) ||
                    helper(board, word, row, col + 1, index + 1) ||
                    helper(board, word, row, col - 1, index + 1)) {
                    return true;
                }

                // Backtrack: restore the original value
                board[row][col] = temp;
            }
        }

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