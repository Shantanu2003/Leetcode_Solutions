class Solution {
public:
    int minimumPushes(std::string word) {
        unordered_map<char, int> mp;

        for (char c : word) {
            mp[c]++;
        }
        vector<int>freq(26,0);
        for(auto i : mp)
        freq.push_back(i.second);

        sort(freq.rbegin(), freq.rend());

        int res = 0;
        int i = 1;

        for (int i = 0 ; i < 26 ; i++) {
            if(freq[i] == 0)break;
            res += (i / 8 + 1) * freq[i];
        }


        return res;
    }
};