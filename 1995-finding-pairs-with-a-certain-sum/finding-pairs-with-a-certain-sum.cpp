class FindSumPairs {
public:
     vector<int>& nums1;
    vector<int>& nums2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : nums2)
            mp[num]++;
    }

    void add(int index, int val) {
        int original = nums2[index];
        nums2[index] += val;
        mp[original]--;
        mp[nums2[index]]++;
    }

    int count(int tot) {
        int count = 0;
        for (int num : nums1) {
            count += mp[tot - num];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */