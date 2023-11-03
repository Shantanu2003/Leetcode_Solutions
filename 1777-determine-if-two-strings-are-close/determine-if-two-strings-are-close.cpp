class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if (word1.size() != word2.size()) {
            return false; 
        }

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        unordered_set<char> chars1;
        unordered_set<char> chars2;

        for (char c : word1) {
            mp1[c]++;
            chars1.insert(c);
        }
        for (char c : word2) {
            mp2[c]++;
            chars2.insert(c);
        }

        if (chars1 != chars2) {
            return false;  
        }

        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;

        for (const auto& pair : mp1) {
            freq1[pair.second]++;
        }

        for (const auto& pair : mp2) {
            freq2[pair.second]++;
        }

        return freq1 == freq2;
    }
};