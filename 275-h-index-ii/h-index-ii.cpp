class Solution {
public:
    int hIndex(vector<int>& citations) {
         int n = citations.size();
        int store = 0;
        for(int i = 0 ; i < citations.size() ; i++){
           if(citations[i] >= n-i){ 
           store = n-i;
           break;
    }
    }
    return store; 
    }
};