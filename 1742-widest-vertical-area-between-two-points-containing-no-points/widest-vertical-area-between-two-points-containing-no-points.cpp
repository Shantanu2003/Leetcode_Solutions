class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        priority_queue<int> pq;
        int res = -1;
        for(int i = 0; i < points.size();i++){
          pq.push(points[i][0]);
        }
        while(!pq.empty()){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            res = max(res,(top1 - top2));
        }
        return res;
    }
};