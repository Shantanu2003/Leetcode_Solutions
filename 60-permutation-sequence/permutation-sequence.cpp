class Solution {
private:
public:
    string getPermutation(int n, int k) {
        string res="";
        for(int  i = 1; i <= n; i++)
        res += to_string(i);

        for (int i = 1; i < k; ++i) {
        if (!next_permutation(res.begin(), res.end())) {
            // If there are fewer than k permutations, return an empty string
            return "";
        }
    }
    return res;
    }
};