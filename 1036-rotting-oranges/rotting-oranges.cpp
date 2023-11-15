class Solution {
public:
    bool isvalid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;  // Count of fresh oranges
        int dis = 0;

        // Enqueue all cells with 2 (rotten oranges)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }

        // If there are no fresh oranges initially, return 0
        if (freshOranges == 0) {
            return 0;
        }

        while (!q.empty()) {
            int size = q.size();  // Store the current size of the queue

            // Process all nodes at the current level (minutes)
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();

                // Explore neighbors
                for (auto& x : dir) {
                    int a = curr.first + x[0];
                    int b = curr.second + x[1];

                    // Check if the neighbor is a valid cell and has a fresh orange
                    if (isvalid(a, b, m, n) && grid[a][b] == 1) {
                        q.push({a, b});
                        grid[a][b] = 2;  // Mark the fresh orange as rotten
                        freshOranges--;
                        if (freshOranges == 0) {
                            return dis + 1;  // All fresh oranges are rotten
                        }
                    }
                }
            }

            // Increment the number of minutes
            dis++;
        }

        // If there are still fresh oranges remaining, return -1
        return -1;
    }
};
