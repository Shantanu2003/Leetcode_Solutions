class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int n = chalk.size();
        long long sum = 0;
        for(int i : chalk)
        sum += i;

        while(k > sum){
            k -= sum;
        }

         while(k > -1){
            int index = i % n;
            k = k - chalk[index];
            i++;
            if(k < 0)
            return index;
        }



        return -1;
    }
};