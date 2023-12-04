class Solution {
public:
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, vector<bool>& inStack, vector<int>& res) {
        if (inStack[node]) {
            // Cycle detected
            return false;
        }
        if (visit[node]) {
            return true;
        }

        visit[node] = true;
        inStack[node] = true;

        for (auto neighbor : adj[node]) {
            if (!dfs(neighbor, adj, visit, inStack, res)) {
                // Propagate the cycle detection
                return false;
            }
        }

        inStack[node] = false;
        res.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>res;
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<bool> visit(numCourses);
        vector<bool> inStack(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i] && !dfs(i, adj, visit, inStack, res)) {
                // Cycle detected, return an empty array
                return {};
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};