class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        // Iterate through the array to satisfy the conditions
        for (int i = 1; i < arr.size(); i++) {
            // Ensure the absolute difference between adjacent elements is less than or equal to 1
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        // The maximum element is now at the end of the sorted and updated array
        return arr[arr.size() -1];
    }
};