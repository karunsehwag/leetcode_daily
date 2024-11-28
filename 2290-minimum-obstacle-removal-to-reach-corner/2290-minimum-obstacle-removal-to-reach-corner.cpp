class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<int> dir = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        dp[0][0] = grid[0][0];
        q.push({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = i + dir[k];
                int ny = j + dir[k + 1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newObstacles = dp[i][j] + grid[nx][ny];
                    if (newObstacles < dp[nx][ny]) {
                        dp[nx][ny] = newObstacles;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
