class Solution {
public:
    int bestClosingTime(string customers) {
        int cur_penalty = count(customers.begin(), customers.end(), 'Y');
        int min_penalty = cur_penalty;
        int earliestHour = 0;

        for(int i =0; i< customers.size(); i++){
            if(customers[i] == 'Y'){
                cur_penalty -= 1;
            }
            else{
                cur_penalty++;
            }
            if(cur_penalty < min_penalty){
                earliestHour = i+1;
                min_penalty = cur_penalty;
            }
        }
        return earliestHour;
    }
};