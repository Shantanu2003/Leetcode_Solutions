class Solution {
public:
    void visitRooms(int room, vector<vector<int>>& rooms, unordered_set<int>& visited) {
        visited.insert(room);  // Mark the current room as visited

        for (int key : rooms[room]) {
            if (visited.find(key) == visited.end()) {
                visitRooms(key, rooms, visited);  // Recursively visit unvisited rooms
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        visitRooms(0, rooms, visited);  // Start visiting rooms from room 0
        return visited.size() == rooms.size();
    }
};
