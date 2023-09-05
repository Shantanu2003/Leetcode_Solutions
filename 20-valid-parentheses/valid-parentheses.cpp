#include <bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
            stack<char> st;
            char c;
            bool flag =true;
            //if(s.size() == 1)flag = false;

            for(int i =0; i<s.size(); i++){
   
                if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                    c=s[i];
                    st.push(c);
                }
                else{
                   if(st.empty())
                   return false;

                   else if(st.top()== '(' && s[i] != ')') 
                   return false;

                   else if (st.top()== '{' && s[i] != '}')
                   return false;

                   else if(st.top()== '[' && s[i] != ']')
                   return false;


                   else
                   st.pop();
                }

            }     
    return st.empty();
    }
};