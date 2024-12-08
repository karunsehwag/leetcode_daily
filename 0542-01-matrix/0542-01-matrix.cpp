class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Initialize a matrix to store the distances, with all elements set to INT_MAX
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));

        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j}); 
                    distances[i][j] = 0;
                }
            }
        }


        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    if (distances[newX][newY] == INT_MAX) { 
                        distances[newX][newY] = distances[x][y] + 1; 
                        q.push({newX, newY});
                    }
                }
            }
        }

        return distances;
    }
};