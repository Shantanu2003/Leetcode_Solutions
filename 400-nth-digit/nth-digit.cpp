class Solution {
public:
    int findNthDigit(int n) {
    if (n < 10) {
        return n;
    }

    long long digits = 1;
    long long count = 9;
    
    while (n > digits * count) {
        n -= digits * count;
        digits++;
        count *= 10;
    }

    long long num = pow(10, digits - 1) + (n - 1) / digits;
    int position = (n - 1) % digits;

    // Find the digit within the number
    while (position < digits - 1) {
        num /= 10;
        position++;
    }

    return num % 10;
    }
};