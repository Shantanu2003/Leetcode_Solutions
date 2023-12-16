class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.size() != t.size())
            return false;

        vector<int> charCount(26, 0); // Assuming input consists of lowercase English letters

        for (char c : s) {
            charCount[c - 'a']++;
        }

        for (char c : t) {
            charCount[c - 'a']--;
        }

        for (int count : charCount) {
            if (count != 0)
                return false;
        }

        return true;
    }
};