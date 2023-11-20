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
        for(int i =1; i<travel.size() ;i++){
            travel[i] += travel[i-1];
        }
        if(maxG > 0) totalSum+= travel[maxG-1];
        if(maxM > 0) totalSum+= travel[maxM-1];
        if(maxP > 0) totalSum+= travel[maxP-1];
        return totalSum+m+p+g;
    }
};