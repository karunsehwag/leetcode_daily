#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // If the starting point has a time constraint > 0, return -1
         if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<int> dir = {-1, 0, 1, 0, -1};

        dp[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;
            if (x == n - 1 && y == m - 1) return time;

            if (time > dp[x][y]) continue;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int wait = (grid[nx][ny] - time) % 2 == 0 ? 1 : 0;
                    int nextTime = max(grid[nx][ny] + wait, time + 1);

                    if (nextTime < dp[nx][ny]) {
                        dp[nx][ny] = nextTime;
                        pq.push({nextTime, {nx, ny}});
                    }
                }
            }
        }

        return -1; 
    }
};
