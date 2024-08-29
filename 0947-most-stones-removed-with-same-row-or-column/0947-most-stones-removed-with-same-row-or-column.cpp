class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> mp;

        // Create adjacency list for rows and columns
        for (int i = 0; i < stones.size(); i++) {
            mp[stones[i][0]].push_back(stones[i][1] + 10001); // Offset for column values
            mp[stones[i][1] + 10001].push_back(stones[i][0]); // Reverse mapping for DFS
        }

        vector<int> vis(20002, 0); // Larger size to accommodate the offset

        // DFS to count connected components
        int components = 0;
        for (int i = 0; i < stones.size(); i++) {
            int x = stones[i][0];  // Row
            if (!vis[x]) {
                components++;
                dfs(x, mp, vis);
            }
        }

        return stones.size() - components; // Max moves = total stones - connected components
    }

    // Depth-first search
    void dfs(int node, unordered_map<int, vector<int>>& mp, vector<int>& vis) {
        vis[node] = 1;
        for (int neighbor : mp[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, mp, vis);
            }
        }
    }
};
