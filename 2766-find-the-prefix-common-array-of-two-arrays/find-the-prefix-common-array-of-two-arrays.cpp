class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>mp(A.size() + 1,0);
        vector<int>ans(A.size());
        int count = 0;
        for(int i = 0 ; i < A.size() ; i++){

            mp[A[i]]++;
            if(mp[A[i]] == 2)
            ++count;

            mp[B[i]]++;
            if(mp[B[i]] == 2)
            ++count;


            ans[i] = count;

        }
        return ans;
    }
};
/*
mp = [0,2,2,2,2]
mp = [0,2,2,2]
*/