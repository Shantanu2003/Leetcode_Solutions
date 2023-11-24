class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i = 0;
        int you = 0;
        int  j = piles.size();
        while(i<j && j > 0 && i < piles.size()){
            you += piles[j-2];
            j=j-2;
            i++;
        }
        return you;
    }
};