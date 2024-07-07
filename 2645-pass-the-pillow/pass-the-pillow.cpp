class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = 1;
        int i = 1;
        while(time > 0){
        i  += direction;
            if (i == 1 || i == n) {
                direction = -direction;
            }

        time--;
        }

        return i;
    }
};