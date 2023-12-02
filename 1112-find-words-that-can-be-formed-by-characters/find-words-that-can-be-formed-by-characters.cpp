class Solution {
public:
    int countCharacters(vector<string>& words, const string& chars) {
        unordered_map<char, int> charFreq;
        int ans = 0;

        // Calculate frequency of each character in chars
        for (char c : chars) {
            charFreq[c]++;
        }

        // Iterate through each word in the vector
        for (const string& word : words) {
            // Check if the word can be formed from chars
            if (canFormWord(word, charFreq)) {
                ans += word.length();
            }
        }

        return ans;
    }

private:
    bool canFormWord(const string& word, unordered_map<char, int>& charFreq) {
        unordered_map<char, int> wordFreq;

        // Calculate frequency of each character in the word
        for (char c : word) {
            wordFreq[c]++;
        }

        // Check if the word can be formed from chars
        for (const auto& [c, freq] : wordFreq) {
            if (freq > charFreq[c]) {
                return false;
            }
        }

        return true;
    }
};

