class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int  i = 1 ; i < points.size() ; i++){
            int x_cord = abs(points[i][0] - points[i - 1][0]);
            int y_cord = abs(points[i][1] - points[i - 1][1]);
            ans += max(x_cord, y_cord);
        }
        return ans;
    }
};