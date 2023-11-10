class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, unordered_set<int>> adjList;
        unordered_map<int, int> degrees;

        // Create an adjacency list and calculate the degrees of each node
        for (auto pair : adjacentPairs) {
            adjList[pair[0]].insert(pair[1]);
            adjList[pair[1]].insert(pair[0]);
            degrees[pair[0]]++;
            degrees[pair[1]]++;
        }

        // Find the start node, which has only one connection
        int start = 0;
        for (auto &degree : degrees) {
            if (degree.second == 1) {
                start = degree.first;
                break;
            }
        }

        vector<int> result;
        unordered_set<int> visited;

        // Traverse the adjacency list to reconstruct the array
        reconstructArray(start, adjList, visited, result);

        return result;
    }

    void reconstructArray(int current, unordered_map<int, unordered_set<int>>& adjList, unordered_set<int>& visited, vector<int>& result) {
        visited.insert(current);
        result.push_back(current);

        for (int neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                reconstructArray(neighbor, adjList, visited, result);
            }
        }
    }
};