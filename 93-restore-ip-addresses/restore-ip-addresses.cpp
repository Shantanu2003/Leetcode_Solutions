class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> result;
        dfs(result, s, 0,"");
        return result;

    }
    void dfs(vector<string> &result, string &s, int start, string current) {
    if (start == s.length() && count(current.begin(), current.end(), '.') == 3) {
        result.push_back(current);
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (start + i <= s.length()) {
            string segment = s.substr(start, i);
            if ((segment[0] != '0' || segment.size() == 1) && stoi(segment) <= 255) {
                dfs(result, s, start + i, current + segment + (start + i == s.length() ? "" : "."));
            }
        }
    }
}
};