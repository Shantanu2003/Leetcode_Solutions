class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>count;
        for(int i = 0 ; i<arr.size(); i++){
            count[arr[i]]++;
        }
        int cutoff = 0.25*arr.size();

        for(auto i: count){
        if(i.second > cutoff){
            return i.first;
            break ;
        }
        }
        return -1;
    }
};