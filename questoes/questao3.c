class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> result;

    void dfs(string u) {
        while (!adj[u].empty()) {
            string v = adj[u].back();
            adj[u].pop_back();
            dfs(v);
        }
        result.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }
        for (auto& it : adj) {
            sort(it.second.begin(), it.second.end(), greater<string>());
        }
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};