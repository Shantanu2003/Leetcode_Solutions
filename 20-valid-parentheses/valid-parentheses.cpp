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
                    flag= false;

                   else if(st.top()== '(' && s[i] != ')') 
                   flag= false;

                   else if (st.top()== '{' && s[i] != '}')
                   flag= false;

                   else if(st.top()== '[' && s[i] != ']')
                   flag= false;

                   else
                   st.pop();
                }

            }
            
    if(!st.empty()){
    flag = false;
    }
    return flag;
    }
};