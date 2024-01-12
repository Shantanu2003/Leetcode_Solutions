// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0; 
        int high = n;
        if(n == 1)
        return 1;

        while(low <= high){
            int mid = low + (high -low)/2;

            if(isBadVersion(mid)){
            high = mid-1;
            low = 0;
            }

            else
            low = mid +1;
        }
        return low;
    }
};