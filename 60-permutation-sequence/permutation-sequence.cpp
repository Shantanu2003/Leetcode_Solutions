class Solution {
private:
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums;

        // Initialize nums with numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        // Factorial array to compute factorials quickly
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            factorial[i] = i * factorial[i - 1];
        }

        // Adjust k to 0-based index
        --k;

        for (int i = n; i > 0; --i) {
            int index = k / factorial[i - 1];
            k %= factorial[i - 1];
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
        }

        return result;
    }
};