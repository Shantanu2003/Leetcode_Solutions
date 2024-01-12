class Solution {
public:
    bool halvesAreAlike(string s) {
        string res1 ="", res2 = "";
        int count1= 0 ,count2 = 0;
        for(int i = 0; i < (s.size()/2) ; i++){
            res1 += s[i];
        }
        for(int  i = (s.size() / 2); i < s.size() ; i++){
            res2 += s[i]; 
        }
        
        for(int i = 0 ; i < res1.size(); i++){
            if(res1[i] == 'a' || res1[i] =='e' || res1[i] =='i' || res1[i] =='o' ||res1[i] =='u' || res1[i] =='A' || res1[i] =='E' ||res1[i] =='I' || res1[i] =='O' || res1[i] =='U')
            count1++;
             if(res2[i] == 'a' || res2[i] =='e' || res2[i] =='i' || res2[i] =='o' ||res2[i] =='u' || res2[i] =='A' || res2[i] =='E' ||res2[i] =='I' || res2[i] =='O' || res2[i] =='U')
            count2++;
        }
    return count1 == count2;
    
    }
};