class Solution {
public:
struct comp {
    // Operator() overloading
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        // new definition
        return p1.second > p2.second;
    }
};
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        unordered_map<int,int>ans;
        for(int i = 0 ; i < arr.size() ; i++){
            ans[arr[i]]++;
        }
        for(auto i : ans){
            pq.push(make_pair(i.first, i.second));
        }
        while(!pq.empty() && k > 0){
            auto head = pq.top();
            if(head.second <= k){
                pq.pop();
                k -= head.second;
            }
            else
            break;
        }
        return pq.size();

    }
};