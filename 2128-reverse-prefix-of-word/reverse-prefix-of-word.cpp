class Solution {
public:
    string reversePrefix(string word, char ch) {
        string res= "";
        string part = "";
        int index = -1;
        for(int i = 0 ; i < word.size(); i++){
            if(word[i] == ch){
                index = i;
                part = word.substr(0,index+1);
                break;
            }
        }
        if(index == -1)
        return word; 
        
        reverse(part.begin() , part.end());
        res = part + word.substr(index+1, word.size() -1);

        return res;
    }
};