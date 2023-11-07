class RecentCounter {
public:
    queue<int> q;
    int count;
    queue<int> tempq;
    RecentCounter() {
        count = 0;
    }
    
    int ping(int t) {
        count=0; 
        q.push(t);
        while(!q.empty()){
            if(q.front()>= (t-3000)){
                tempq.push(q.front());
                count++;
            }

            q.pop();
        }
        while (!tempq.empty()) {
            q.push(tempq.front());
            tempq.pop();
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */