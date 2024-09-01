#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;  // Blocked path edge case

        // Min-heap priority queue: {distance, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;  // Distance starts from 1 because (0,0) is a valid cell

        pq.push({1, {0, 0}});

        // Directions for 8 possible movements
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // If we have reached the bottom-right corner, return the distance
            if (r == n-1 && c == n-1) return dis;

            // Explore all 8 directions
            for (int i = 0; i < 8; i++) {
                int newr = r + dx[i];
                int newc = c + dy[i];

                // Check bounds and if the new cell is walkable (grid[newr][newc] == 0)
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = dis + 1;
                    pq.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;  // No path found
    }
};
