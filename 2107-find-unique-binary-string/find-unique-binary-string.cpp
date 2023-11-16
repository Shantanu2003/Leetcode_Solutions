class Solution {
public:

vector<bitset<32>> helper(int n) {
    vector<bitset<32>> combinations;

    for (int i = 0; i < (1 << n); ++i) {
        combinations.push_back(i);
    }

    return combinations;
}
   string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>ans;
        int n = nums[0].size();
        vector<bitset<32>> combinations;


        for(int  i = 0 ; i  <nums.size() ; i++){
            ans.insert(nums[i]);
        }

        combinations = helper(n);
        
        vector<string> stringVector;
        for (const auto& binary : combinations) {
            stringVector.push_back(binary.to_string().substr(32 - n));
        }
        string res="";
        for(int i = 0 ; i < stringVector.size() ; i++){
            if(ans.find(stringVector[i]) == ans.end()){
               res = stringVector[i];
               break;
            }
        }
    return res;
    }
};