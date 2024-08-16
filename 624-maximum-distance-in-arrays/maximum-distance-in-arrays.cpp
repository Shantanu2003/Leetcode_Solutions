class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDif = 0, curMin = 10000, curMax = -10000;
        for (auto& a : arrays) {
            maxDif = max(maxDif, max(a.back()-curMin, curMax-a.front()));
            curMin = min(curMin, a.front()), curMax = max(curMax, a.back());
        }
        return maxDif;
    }
};

/*
diff = 0
currmin = 1
curr max = 3

diff = 5-1, 3-4 = 4
currmin = 1
currmax = 5

diff = 3-1, 5-1 = 4
currmin = 1
currmax = 5

{2,3,4}{1,5}{2,3,4}

diff = 4-1000, -1000-1, 0 = 0
currmin = 2
currmax = 4

diff = 5-2, 4-1 = 3
currmin = 1
currmax = 5

diff = 4-1, 5-2 = 3
currmin = 1
currmax = 5 */