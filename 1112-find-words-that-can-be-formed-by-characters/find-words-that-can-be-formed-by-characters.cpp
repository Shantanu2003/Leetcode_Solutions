class Solution {
public:
    bool isFind(const string& s, const unordered_map<char, int>& mp) {
        unordered_map<char, int> mp1;
        for (char c : s) {
            mp1[c]++;
        }

        for (const auto& kv : mp1) {
            // Check if the key exists in the map before using at()
            if (mp.find(kv.first) == mp.end() || kv.second > mp.at(kv.first)) {
                return false;
            }
        }
        return true;
    }

    int countCharacters(vector<string>& words, const string& chars) {
        unordered_map<char, int> mp;
        int ans = 0;

        for (char c : chars) {
            mp[c]++;
        }

        for (const string& word : words) {
            // Check if the word can be formed from chars
            if (isFind(word, mp)) {
                ans += word.length();
            }
        }

        return ans;
    }
};