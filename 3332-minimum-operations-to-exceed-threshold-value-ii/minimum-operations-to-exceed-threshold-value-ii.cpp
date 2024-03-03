class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int operations = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i : nums)
    pq.push(i);
    while(pq.top() < k && pq.size() >= 2){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        long long new_value = min(x,y)* 2LL + max(x,y);
        pq.push(new_value);
        operations++; 
    }
    
    return operations;
        
    }
};