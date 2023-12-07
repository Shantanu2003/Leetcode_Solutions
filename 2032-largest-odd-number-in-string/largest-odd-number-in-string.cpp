class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int index= 0;
        for(int i = num.size() - 1; i >= 0 ; i--){
            char c = num[i];
            if((c -'0') % 2 != 0){
                index = i+1;
                break;
            }
        }
        for(int i = 0; i < index; i++){
          res += num[i];
        }
    return res;
    }
};