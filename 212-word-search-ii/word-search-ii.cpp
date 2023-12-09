#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    void backtrack(vector<vector<char>>& board, int i, int j, TrieNode* node, string& current, unordered_set<string>& result) {
        char ch = board[i][j];
        TrieNode* child = node->children[ch];

        if (child == nullptr) {
            return;  // No matching word in the Trie
        }

        current.push_back(ch);
        board[i][j] = '#';  // Mark the cell as visited

        if (child->isEnd) {
            result.insert(current);  // Found a valid word
            child->isEnd = false;    // Avoid duplicate results
        }

        int m = board.size();
        int n = board[0].size();

        // Explore adjacent cells
        if (i > 0) backtrack(board, i - 1, j, child, current, result);
        if (i < m - 1) backtrack(board, i + 1, j, child, current, result);
        if (j > 0) backtrack(board, i, j - 1, child, current, result);
        if (j < n - 1) backtrack(board, i, j + 1, child, current, result);

        board[i][j] = ch;  // Backtrack: restore the original value
        current.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        unordered_set<string> result;
        string current;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(board, i, j, trie.getRoot(), current, result);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};
