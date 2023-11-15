class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Create a visited matrix to mark visited cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    // Queue to store cells to be visited along with the number of steps
    queue<pair<pair<int, int>, int>> q;
    
    // Enqueue the entrance cell along with the number of steps (initially 0)
    q.push({{entrance[0], entrance[1]}, 0});
    visited[entrance[0]][entrance[1]] = true;
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int row = current.first.first;
        int col = current.first.second;
        int steps = current.second;
        
        // Check if the current cell is at the border (exit)
        if ((row == 0 || row == m - 1 || col == 0 || col == n - 1) && steps > 0) {
            return steps;
        }
        
        // Explore neighbors
        for (const auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            
            // Check if the new cell is within bounds and is an empty cell
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                q.push({{newRow, newCol}, steps + 1});
                visited[newRow][newCol] = true;
            }
        }
    }
    
    // No exit found
    return -1;
    }
};