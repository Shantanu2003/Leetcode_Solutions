class Solution {
public:
    string convertBit(int n){
        string ans = "";
        int temp = n;
        while(temp > 0){
            int a = temp % 2;
            ans += to_string(a);
            temp /= 2;
        }
    return ans;
    }
    int minOperations(vector<int>& nums, int k) {
        int res = nums[0]; 
        for(int i = 1 ; i < nums.size() ; i++){
            res ^= nums[i];
        }

        if(res == k)
        return 0;

        string res1 = convertBit(res);
        string k1 = convertBit(k);

        if(res1.size() > k1.size()){
            while(k1.size() < res1.size())
            k1 += '0';
        }
        else{
            while(res1.size() < k1.size())
            res1 += '0';
        }

        int count0 = 0, count1 = 0;

        int count = 0;
        for(int i = 0 ; i < res1.size() ; i++){
            if(res1[i] != k1[i])
            count++;
        }
        return count;

    }
};