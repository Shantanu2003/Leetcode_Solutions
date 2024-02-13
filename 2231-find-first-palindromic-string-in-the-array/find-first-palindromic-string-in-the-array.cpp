class Solution {
public:
    bool isPalindrome(string& s) {
        int start = 0;
        int end = s.size() - 1;
        bool flag =true;
        while (start <= end) {
            // Return false if the characters are not the same.
            if (s[start] == s[end]) {
                   start++;
                   end--;
            }
            else{
                flag = false;
                break;
            }  
        }
        
        return flag;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            if (isPalindrome(s)) {
                return s;
            }
        }
        
        return "";
    }
};