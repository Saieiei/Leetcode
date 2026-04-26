//dfs
// This block disables I/O synchronization to speed up execution time on LeetCode
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, const int color, const int m, const int n, const int originalColor){
        //1st check if the coordinates r safe
        if((sr<0 || sr>=m)||(sc<0 || sc>=n)||(image[sr][sc] != originalColor)){
            return;
        }

        //its safe to color it
        image[sr][sc] = color;

        //spread the infection in 4 directions
        dfs(image, sr-1, sc, color, m, n, originalColor);
        dfs(image, sr+1, sc, color, m, n, originalColor);
        dfs(image, sr, sc-1, color, m, n, originalColor);
        dfs(image, sr, sc+1, color, m, n, originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
    
        //you only want to spread the color to adjacent pixels that 
        //match the original color of the starting pixel.
        int originalColor = image[sr][sc];
        //check if the coordinates color is not the given color
        if(color != image[sr][sc]){
            dfs(image, sr, sc, color, m, n, originalColor);
        }
        return image;
    }
};