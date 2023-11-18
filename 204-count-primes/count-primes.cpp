class Solution {
public:
    int countPrimes(int n) {
    vector<bool> isPrime(n+1, true); // Initialize all numbers as prime
    int count = 0;
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p < n; ++p) {
        if (isPrime[p]) {
            // Mark all multiples of p as not prime
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for(int p = 0; p < isPrime.size()-1; ++p){
        if(isPrime[p] == true)
        count++;
    }
    return count;
    }
};