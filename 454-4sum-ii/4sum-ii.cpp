class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int count = 0;

        // Create a hash map to store the frequencies of sums of pairs from nums1 and nums2
        unordered_map<int, int> sumFreq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumFreq[nums1[i] + nums2[j]]++;
            }
        }

        // Check for complements in nums3 and nums4
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int complement = -(nums3[k] + nums4[l]);
                    count += sumFreq[complement];
            }
        }

        return count;

    }
};

