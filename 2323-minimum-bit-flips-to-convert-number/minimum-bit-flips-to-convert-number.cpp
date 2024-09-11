class Solution {
public:
    string convertBinary(int num) {
        string res = "";
        while (num > 0) {
            res += to_string(num % 2);
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;  // Handle the case where num is 0
    }

    int minBitFlips(int start, int goal) {
        string s = convertBinary(start);
        string g = convertBinary(goal);

        // Ensure both strings have the same length by padding the shorter one with leading zeros
        if (s.size() > g.size()) {
            g = string(s.size() - g.size(), '0') + g;
        } else {
            s = string(g.size() - s.size(), '0') + s;
        }

        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != g[i]) {
                count++;
            }
        }

        return count;
    }
};
