class Solution {
public:
    bool bfs(int n, vector<vector<int>>& edges, int start, int destination,vector<vector<int>>&mp,vector<bool>& visited){
        queue<int> q;
        visited[start] = true;
        q.push(start);
    
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            if(currentNode == destination)
            return true;
    
            for (int neighbor : mp[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>mp(n);
        for(int  i = 0 ; i < edges.size() ; i++){
            int from = edges[i][0];
            int to = edges[i][1];

            mp[from].push_back(to);
            mp[to].push_back(from);
        }
        vector<bool>visited(n,false);
        return bfs(n, edges, source, destination,mp,visited);
    }
};