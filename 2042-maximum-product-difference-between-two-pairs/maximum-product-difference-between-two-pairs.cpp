class Solution {
public:
pair<int, int> findTwoMaximum(vector<int>& arr) {

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
pair<int, int> findTwoMinimum(vector<int>& arr) {

    int first_min = INT_MAX;  // Initialize the first maximum to negative infinity
    int second_min = INT_MAX; // Initialize the second maximum to negative infinity

    for (int num : arr) {
        if (num < first_min) {
            second_min = first_min;
            first_min = num;
        } else if (num < second_min) {
            second_min = num;
        }
    }

    return {first_min, second_min};
}
    int maxProductDifference(vector<int>& nums) {
        auto result1 = findTwoMaximum(nums);
        auto result2 = findTwoMinimum(nums);

        return ((result1.first*result1.second) - (result2.first*result2.second));

    }
};