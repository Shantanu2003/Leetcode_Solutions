class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    priority_queue <int, vector<int>, greater<int>>q;

    Graph(int n, vector<vector<int>>& edges) {
        for(int  i =0 ; i<edges.size() ; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            graph[from].push_back({to, weight});
            graph[to]; 
        }
    }
    
    void addEdge(vector<int> edge) {
        int from = edge[0];
        int to = edge[1];
        int weight= edge[2];

        graph[from].push_back({to, weight});
        graph[to]; 
    }
    
    int shortestPath(int node1, int node2) {
        unordered_map<int, int> dist;
        for (auto& node : graph) {
            dist[node.first] = INT_MAX;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        dist[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (u == node2) {
            return dist[u];
        }

            if (d > dist[u]) continue;

            for (auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[node2] == INT_MAX) {
        return -1; // No path found
            }
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */