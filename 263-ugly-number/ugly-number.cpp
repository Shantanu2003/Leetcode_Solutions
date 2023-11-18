class Solution {
public:
    bool isUgly(int n) {
    vector<int> factors;

    if(n <= 0)
    return false;
    // Divide by 2 while n is even
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Try odd numbers starting from 3
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime greater than 2
    if (n > 2) {
        factors.push_back(n);
    }
    for(int factor: factors){
        if(factor !=2 && factor != 3 && factor != 5)
        return false;
    }


    return true;
    }
};