class Solution {
    private:
    int Sum(int n)
{
    int squareSum = 0;
    while (n) {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}
public:
    bool isHappy(int n) {
    set<int>mp;
    while(1){
        n = Sum(n);
        if(n == 1)return true;

        if(mp.find(n)!=mp.end())
        return false;

        mp.insert(n);
    }
    }
};