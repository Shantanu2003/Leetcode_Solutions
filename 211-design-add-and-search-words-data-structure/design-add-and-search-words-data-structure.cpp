class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool isMatch(TrieNode* node, const std::string& word, int index) {
        if (index == word.length()) {
            return node->isEnd;
        }

        char ch = word[index];
        if (ch != '.') {
            if (node->children.find(ch) != node->children.end()) {
                return isMatch(node->children[ch], word, index + 1);
            } else {
                return false;
            }
        } else {
            for (const auto& child : node->children) {
                if (isMatch(child.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return isMatch(root, word, 0);
    }
};