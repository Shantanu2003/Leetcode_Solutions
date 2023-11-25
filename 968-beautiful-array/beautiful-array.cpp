class Solution {
public:
    vector<int> beautifulArray(int n) {
        std::vector<int> result;

        if (n == 1) {
            result.push_back(1);
        } else {
            auto left = beautifulArray((n + 1) / 2);
            auto right = beautifulArray(n / 2);

            for (int num : left) {
                result.push_back(2 * num - 1);
            }

            for (int num : right) {
                result.push_back(2 * num);
            }
        }

        return result;
    }
};