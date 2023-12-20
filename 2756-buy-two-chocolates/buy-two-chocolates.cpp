class Solution {
public:
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
    int buyChoco(vector<int>& prices, int money) {
      auto result = findTwoMinimum(prices);
      int diff = money - result.first - result.second;
      if(diff < 0)
      return money;

      return diff;
    }
};