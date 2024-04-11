class Solution {
public:
    string removeKdigits(string num, int k) {
  std::string result = "";
    
    for (char digit : num) {
        while (k > 0 && !result.empty() && result.back() > digit) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }
    
    // Remove remaining digits if k > 0
    result.resize(result.size() - k);
    
    // Remove leading zeros
    int i = 0;
    while (i < result.length() && result[i] == '0') {
        i++;
    }
    result = result.substr(i);
    
    // If the result is empty, return "0"
    if (result.empty()) {
        return "0";
    }
    
    return result;

    }
};