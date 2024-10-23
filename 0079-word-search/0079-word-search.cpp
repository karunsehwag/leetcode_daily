class Solution {
public:
    bool dp(int i, int j, vector<vector<char>>& board, string& word, int in, vector<vector<int>>& vis) {
        // Base case: if we've matched the entire word
        if (in == word.size() - 1)
            return true;
        
        vector<int> dir = {-1, 0, 1, 0, -1};  // Directions for traversal (up, right, down, left)
        in++;  // Move to the next character in the word
        
        // Explore all four directions
        for (int k = 1; k < dir.size(); k++) {
            int row = i + dir[k - 1];
            int col = j + dir[k];
            
            // Check if the next cell is valid and matches the next character in the word
            if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() &&
                board[row][col] == word[in] && vis[row][col] == 0) {
                
                vis[row][col] = 1;  // Mark as visited
                
                // Recursive call to explore further
                if (dp(row, col, board, word, in, vis))
                    return true;
                
                vis[row][col] = 0;  // Unmark (backtrack) if the path doesn't work out
            }
        }
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));  // Initialize the visited matrix
        
        // Iterate over the board to find the starting point (first character match)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {  // First character match
                    vis[i][j] = 1;  // Mark the start position as visited
                    
                    // Start the depth-first search
                    if (dp(i, j, board, word, 0, vis))
                        return true;
                    
                    vis[i][j] = 0;  // Unmark after the search
                }
            }
        }
        
        return false;  // If no match is found
    }
};
