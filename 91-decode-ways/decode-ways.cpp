class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> count1(n + 1,0);
        count1[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                count1[i] += count1[i - 1] ;
            }

            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                count1[i] += count1[i - 2];
            }
        }


        return count1[n];
    }
};


