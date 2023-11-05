class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int res = arr[0];
        if (k > arr.size()) {
            return *max_element(arr.begin(), arr.end());
        } 
    
        else {
           int count0 = 0;  // Initialize both counts to 0

           for (int i = 1; i < arr.size(); i++) {
               if (arr[i] > res) {
                  res = arr[i];
                  count0 = 1;
               } 
               else {
                count0++;
               }

               if (count0 == k) {
                  return res;
                  break;
               }
           }
        }
        return res;
    }
};