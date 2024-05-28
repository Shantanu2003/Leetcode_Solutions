class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxi = 0;
        int j = 0;
        int curr = 0;
        for(int i = 0 ; i < s.size() ; i++){
            
            curr += abs(s[i] - t[i]);

            while(curr> maxCost){
                curr -= abs(s[j] - t[j]);
                j++;
            }
           
        maxi = max(maxi, i- j +1);
        }

        return maxi;
    }
};