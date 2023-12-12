class Solution {
public:
pair<int, int> findTwoMaximum(std::vector<int>& arr) {

    int first_max = INT_MIN;  // Initialize the first maximum to negative infinity
    int second_max = INT_MIN; // Initialize the second maximum to negative infinity

    for (int num : arr) {
        if (num > first_max) {
            second_max = first_max;
            first_max = num;
        } else if (num > second_max) {
            second_max = num;
        }
    }

    return {first_max, second_max};
}
    int maxProduct(vector<int>& nums) {
    if (nums.size() == 2) {
        return (nums[0]-1) * (nums[1] -1);  // Returning a pair of -1 values as an error indicator
       }
    auto result = findTwoMaximum(nums);

    return (result.first -1) * (result.second -1);
    }
};