class Solution {
public:
    string sortVowels(string s) {
        vector<int> ans;
        vector<int>index;
        for(int i = 0; i<s.size() ; i++){
          if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i]== 'u' || s[i] == 'A' || s[i] == 'E' || s[i]  == 'I'|| s[i] == 'O' || s[i] == 'U'){
             ans.push_back(s[i]);
             index.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
       
        for(int i = 0 ; i < index.size() ; i++){
            s[index[i]] = ans[i];
        }
        return s;
    }
};