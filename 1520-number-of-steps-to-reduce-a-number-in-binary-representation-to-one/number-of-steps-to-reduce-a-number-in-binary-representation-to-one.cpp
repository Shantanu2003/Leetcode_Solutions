class Solution {
public:
    string convertEven(string s){
        int j = s.size() - 1;
        int countzero = 0;
        while(j >= 0){
            if(s[j] == '1'){
                s[j] = '0';
                countzero++;
            }
            else{
                s[j] = '1';
                break;
            }
            j--;
        }
        if(countzero == s.size()){
            s += '1';
            reverse(s.begin(),s.end());

        }
        return s;
    }
    int count = 0;
    int solve(string s){
        if(s == "1"){
            return 0;
        }

        int n = s.size() - 1;

        if(s[n] == '1'){
            s= convertEven(s);
            count++;
        }
        else{
            s.pop_back();  
            count++;
        }

        solve(s);
        return count;
    }
    int numSteps(string s) {
        return solve(s);
    }
};