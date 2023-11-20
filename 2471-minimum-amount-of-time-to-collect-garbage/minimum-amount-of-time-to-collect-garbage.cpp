class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int totalSum = 0;
        int maxG = 0,maxM = 0,maxP = 0;
        int g =0 ,m =0, p = 0;
        for(int s = 0; s<garbage.size(); s++){
            for(int i =0 ; i<garbage[s].size() ; i++){
               if(garbage[s][i] == 'G'){
                   g++;
                   maxG= s;
               }
               else if(garbage[s][i] == 'P'){
                   p++;
                   maxP= s;
               }
               else{
                   m++;
                   maxM= s;
               }
            }
        }
        for(int i = 0 ; i<= maxG-1; i++){
        totalSum += travel[i]; 
        }
        for(int i = 0 ; i<= maxP-1; i++){
        totalSum += travel[i]; 
        }
        for(int i = 0 ; i<= maxM-1; i++){
        totalSum += travel[i]; 
        }
        totalSum += m+g+p;

        return totalSum;
    }
};