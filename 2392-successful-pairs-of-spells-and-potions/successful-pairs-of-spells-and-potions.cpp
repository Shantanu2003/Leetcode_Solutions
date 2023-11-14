class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            int low = 0;
            int high = potions.size() - 1;
            int count = 0;
            while(low <= high){
                int mid = low + (high -low)/2;

                 if ((long long)spells[i] * potions[mid] >= success) {
                    count = potions.size() - mid;
                    high = mid - 1; 
                } else {
                    low = mid +1;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};