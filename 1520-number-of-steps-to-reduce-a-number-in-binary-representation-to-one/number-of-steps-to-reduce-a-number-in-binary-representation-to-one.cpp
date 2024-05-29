class Solution {
public:
 int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            int n = s.size() - 1;
            if (s[n] == '0') {
                // If the last character is '0', just remove it (divide by 2)
                s.pop_back();
            } else {
                // If the last character is '1', we need to handle the carry
                while (n >= 0 && s[n] == '1') {
                    s[n] = '0';
                    n--;
                }
                if (n < 0) {
                    // If we flipped all '1's to '0's and ran out of characters,
                    // we need to add an additional '1' at the beginning
                    s = '1' + s;
                } else {
                    // Change the first '0' we encounter to '1'
                    s[n] = '1';
                }
            }
            steps++;
        }
        return steps;
    }
};