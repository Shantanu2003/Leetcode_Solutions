class Solution {
public:
    int countOrders(int n) {
    long long int ans = 1;
 
    for(int i = 1; i <= n; i++)
    {
       ans = (ans * i * (2 * i - 1))%1000000007;
    }
    return (int)ans;
    }
};