class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool hasPath(int curr, int target) {
        if (curr == target) return true;
        visited[curr] = true;

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                if (hasPath(neighbor, target)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            visited.assign(n + 1, false);

            if (!adj[u].empty() && !adj[v].empty() && hasPath(u, v)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};