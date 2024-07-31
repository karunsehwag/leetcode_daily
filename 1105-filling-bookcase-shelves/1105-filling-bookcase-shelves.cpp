class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> memo(books.size(), -1);
        return dpHelper(books, shelfWidth, memo, 0);
    }
    
    int dpHelper(vector<vector<int>>& books, int shelfWidth, vector<int>& memo, int i) {
        if (i >= books.size()) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int widthRemaining = shelfWidth;
        int maxHeight = 0;
        int height = INT_MAX;
        
        for (int j = i; j < books.size(); ++j) {
            if (books[j][0] > widthRemaining) {
                break;
            }
            
            widthRemaining -= books[j][0];
            maxHeight = max(maxHeight, books[j][1]);
            height = min(height, maxHeight + dpHelper(books, shelfWidth, memo, j + 1));
        }
        
        memo[i] = height;
        return height;
    }
};
