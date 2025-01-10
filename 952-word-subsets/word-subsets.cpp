class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26, 0);

        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                max_freq[i] = max(max_freq[i], freq[i]);
            }
        }
        vector<string> ans;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool res = true;
            for(int i = 0 ; i < 26 ; i++){
                if(freq[i] < max_freq[i]){
                    res = false;
                    break;
                }
            }
            if(res == true)
            ans.push_back(word);
        }
        return ans;
    }
};