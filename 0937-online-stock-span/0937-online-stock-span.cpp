class StockSpanner {
public:
    stack<pair<int, int>> st; 
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;

        while (!st.empty() && price >= st.top().first) {
            ans += st.top().second; // Add the span of the previous day
            st.pop();
        }

        st.push({price, ans});
        
        return ans;
    } 
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */