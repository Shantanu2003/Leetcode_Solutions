class Solution {
private:
int findRoot(int n, vector<int>& left, vector<int>& right) {
    unordered_set<int> children;
    children.insert(left.begin(), left.end());
    children.insert(right.begin(), right.end());
    
    for (int i = 0; i < n; i++) {
        if (children.find(i) == children.end()) {
            return i;
        }
    }
    
    return -1;
}
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       int res = findRoot(n,leftChild, rightChild);

       if(res == -1)
       return false;

       stack<int>st;
       unordered_set<int>seen;
       seen.insert(res);
       st.push(res);
       
       while(!st.empty()){
           int node = st.top();
           st.pop();

           vector<int>child = {leftChild[node], rightChild[node]};

           for(auto c:child){
               if(c != -1){
                   if(seen.find(c)!=seen.end()){
                       return false;
                   }
                   st.push(c);
                   seen.insert(c);
               }
           }
       }
       return seen.size() == n;
    }
};