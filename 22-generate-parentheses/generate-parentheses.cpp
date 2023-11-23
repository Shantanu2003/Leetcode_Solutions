class Solution {
public: 
    void solve(vector<string>& ans, int n, string output, int open, int close) {
        if(output.size() == 2 * n) {
            ans.push_back(output);
            return;
        }

        if (open < n) {
            solve(ans, n, output + '(', open + 1, close);
        }

        if (close < open) {
            solve(ans, n, output + ')', open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = 0;
        int close = 0;
        solve(ans, n, output, open, close);
        return ans;
    }
};