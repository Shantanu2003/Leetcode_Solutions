class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() == 0)
        return n-*min_element(right.begin(), right.end()); 

        if(right.size() == 0)
        return *max_element(left.begin(), left.end());

        int res = 0;
        for(int i = 0; i <left.size(); i++){
          res = max(res, (left[i]));
        }
        for(int i = 0; i <right.size(); i++){
          res = max(res, (n-right[i]));
        }
        return res;
    }
};