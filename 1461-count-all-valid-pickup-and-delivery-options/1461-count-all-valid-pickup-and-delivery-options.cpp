class Solution {
public:
unsigned int fact(unsigned int n)
{
   if (n == 0)
        return 1;
    return n * fact(n - 1);
}
    int countOrders(int n) {
      long long int result = 1;
 
    for(int i = 2; i <= n; i++)
    {
       result = (result * i * (2 * i - 1))%1000000007;
    }
    return (int)result;
    }
};