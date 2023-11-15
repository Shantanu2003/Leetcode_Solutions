class Solution {
public:
      string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();

        // Handle the case when either num1 or num2 is "0"
        if (len1 == 1 && num1[0] == '0' || len2 == 1 && num2[0] == '0') {
            return "0";
        }

        // Initialize a vector to store the result digits
        vector<int> result(len1 + len2, 0);

        // Perform the multiplication
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int digit1 = num1[i] - '0';

            for (int j = len2 - 1; j >= 0; j--) {
                int digit2 = num2[j] - '0';
                int sum = digit1 * digit2 + result[i + j + 1] + carry;
                result[i + j + 1] = sum % 10;
                carry = sum / 10;
            }

            result[i] += carry; // Add the remaining carry to the current position
        }

        // Convert the result vector to a string
        string res;
        for (int digit : result) {
            if (!(res.empty() && digit == 0)) {
                char digitChar = digit + '0';
                res.push_back(digitChar);
            }
        }

        return res.empty() ? "0" : res; 

    }
};