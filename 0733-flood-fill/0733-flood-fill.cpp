class Solution {
public:
    bool isSafe(int newX, int newY, int m, int n, const vector<vector<int>>& output, int originalColor, const vector<vector<bool>>& isVisited) {
        // Check bounds, visited status, and if the color matches the original color
        if((newX < 0 || newX >= m) || (newY < 0 || newY >= n) || 
           (isVisited[newX][newY]) || 
           (output[newX][newY] != originalColor)) {
            return false;
        }
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        // 1. Replaced the map with a 2D vector for O(1) lookups
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        vector<vector<int>> output = image;
        
        int originalColor = image[sr][sc];
        
        // Edge case: if the starting pixel is already the target color, return early
        if (originalColor == color) {
            return output;
        }
        
        queue<pair<int, int>> q;
        
        // Push initial node and mark visited/colored
        q.push({sr, sc});
        output[sr][sc] = color;
        isVisited[sr][sc] = true; 
        
        // Directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()) {
            pair<int, int> frontPair = q.front();
            q.pop();
            
            int x = frontPair.first;
            int y = frontPair.second;
            
            // Explore neighbors
            for(int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                
                if(isSafe(newX, newY, m, n, output, originalColor, isVisited)) {
                    // Infection successful
                    output[newX][newY] = color;
                    isVisited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        return output;
    }
};