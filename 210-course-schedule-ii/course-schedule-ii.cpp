class Solution {
public:
bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& res) {
        if (state[node] == 2) {
            // Already visited
            return true;
        }
        if (state[node] == 1) {
            // Cycle detected
            return false;
        }

        state[node] = 1; // Mark as visiting

        for (auto neighbor : adj[node]) {
            if (!dfs(neighbor, adj, state, res)) {
                // Propagate the cycle detection
                return false;
            }
        }

        state[node] = 2; // Mark as visited
        res.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> res;
        vector<int> state(numCourses, 0); // 0: Not visited, 1: Visiting, 2: Visited

        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && !dfs(i, adj, state, res)) {
                // Cycle detected, return an empty array
                return {};
            }
        }

        reverse(res.begin(), res.end()); // Reverse during construction
        return res;
    }
};