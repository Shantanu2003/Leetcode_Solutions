class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> targetFreq;
    unordered_map<char, int> windowFreq;
    
    // Initialize the target frequency map
    for (char c : t) {
        targetFreq[c]++;
    }
    
    int left = 0, minLen = INT_MAX, minLenStart = 0, count = 0;
    
    for (int right = 0; right < s.size(); right++) {
        char rightChar = s[right];
        
        // Check if the current character is in target string
        if (targetFreq.find(rightChar) != targetFreq.end()) {
            windowFreq[rightChar]++;
            if (windowFreq[rightChar] <= targetFreq[rightChar]) {
                count++;
            }
        }
        
        while (count == t.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLenStart = left;
            }
            
            char leftChar = s[left];
            
            if (targetFreq.find(leftChar) != targetFreq.end()) {
                windowFreq[leftChar]--;
                if (windowFreq[leftChar] < targetFreq[leftChar]) {
                    count--;
                }
            }
            
            left++;
        }
    }
    
    if (minLen == INT_MAX) {
        return "";
    }
    
    return s.substr(minLenStart, minLen);
    }
};