class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int low = 0;
        int n = people.size();
        int high = n - 1;
        int sum = 0;
        int count = 0;
        sort(people.begin(), people.end());
        while(low <= high){
            sum = people[low] + people[high];
            if(sum <= limit){
                 low++;
                 high--;
            }
            else{
                high--;
            }
             count++;

        }
        return count;
    }
};