class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int  i = 0 ; i < score.size() ; i++){
            pq.push({score[i], i});
        }

        vector<string>res(score.size());
        auto top1 = pq.top();
        res[top1.second] = "Gold Medal";
        pq.pop();

        if(!pq.empty()){
        auto top2 = pq.top();
        res[top2.second] = "Silver Medal";
        pq.pop();  
        }
        if(!pq.empty()){
        auto top3 = pq.top();
        res[top3.second] = "Bronze Medal";
        pq.pop();
        }
                
        int counter = 4;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            res[front.second] = to_string(counter);
            counter++;
        }
        return res;
    }
};