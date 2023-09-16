class Solution {
public:
    string removeStars(string s) {
       stack<int> st;
       string str="";
       for(auto j:s){
           if(j!='*'){
               st.push(j);
           }
           else{
               st.pop();
           }
       } 
       while(!st.empty()){
           str += st.top();
           st.pop();
       }
       reverse(str.begin(),str.end());
       return str;
    }
};