class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int indx = -1;
        int max_ele = 0;
        bool flag = false, flag1 = false;
        if(arr[0] == 1){
            flag1 = true;
        }
        else{
            arr[0] = 1;
            flag1 = true;
        }

        if(flag1 == true){
            flag = true;
            for(int i = 1; i < arr.size() ; i++){
                if(arr[i] - arr[i-1] > 1){
                    flag = false;
                    indx = i;
                    break;
                }
            }
        }
       
        if(flag == true){
            max_ele = arr[arr.size() - 1];
        }

        else{
            arr[indx] = arr[indx -1]+1; 
            for(int i = indx + 1; i < arr.size() ; i++){
                if(arr[i] - arr[i-1] > 1)
                arr[i] = arr[i-1] +1;
            }
            max_ele = arr[arr.size() - 1];

        }
        return max_ele;
    }
};