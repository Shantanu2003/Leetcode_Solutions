class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int index= 0;
        for(int i = num.size() - 1; i >= 0 ; i--){
            char c = num[i];
            if((c -'0') % 2 != 0){
                return num.substr(0,i+1);
            }
        }
    return "";
    }
};