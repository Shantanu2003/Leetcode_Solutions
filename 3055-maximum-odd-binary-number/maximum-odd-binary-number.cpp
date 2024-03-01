class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int low = 0;
        int high = 0;
        while(high < s.size()){
            if(s[high] == '1'){
                swap(s[high], s[low]);
                low++;
            }
            high++;
        }
        s[low-1] = '0';
        s[high-1] = '1';

        return s;
    }
};