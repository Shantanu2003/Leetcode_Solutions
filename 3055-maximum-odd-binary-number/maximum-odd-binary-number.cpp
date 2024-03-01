class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOne = 0;
        for(char c :s){
            if(c == '1')
            countOne++;
        }
        int countZero = s.size() - countOne;
        string res = "";
        for(int  i = 0 ; i < countOne-1 ; i++)
        res += '1';

        for(int  i = 0 ; i < countZero ; i++)
        res += '0';

        return res + '1';
    };
};