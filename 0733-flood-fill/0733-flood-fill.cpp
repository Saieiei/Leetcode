//dfs
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, const int& color, const int& originalColor){
        int m = image.size();
        int n = image[0].size();

        //1st check if the coordinates r safe
        if((sr<0 || sr>=m)||(sc<0 || sc>=n)||(image[sr][sc] != originalColor)){
            return;
        }

        //its safe to color it
        image[sr][sc] = color;

        //spread the infection in 4 directions
        dfs(image, sr-1, sc, color, originalColor);
        dfs(image, sr+1, sc, color, originalColor);
        dfs(image, sr, sc-1, color, originalColor);
        dfs(image, sr, sc+1, color, originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //you only want to spread the color to adjacent pixels that 
        //match the original color of the starting pixel.
        int originalColor = image[sr][sc];
        //check if the coordinates color is not the given color
        if(color != image[sr][sc]){
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};