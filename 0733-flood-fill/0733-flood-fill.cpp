//bfs
class Solution {
public:
    bool isSafe(const int newX, const int newY, const int m, const int n, vector<vector<int>>& image, const int color, const int originalColor){
        if((newX<0 || newX>=m)||(newY<0 || newY>=n)||(image[newX][newY] == color)
        ||((image[newX][newY] != originalColor))){
            return false;
        }
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //create isVisited
        int m = image.size();
        int n = image[0].size();
        //we will not create a isVisited as we will directly change the image
        //in place optimization
        //create a q
        queue<pair<int, int>> q;
        //1st mark it as visited
        int originalColor; 
        if(image[sr][sc] != color){
            q.push({sr, sc});
            originalColor = image[sr][sc];
            image[sr][sc] = color;
        }
        //to explore its nbrs
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            pair<int, int> frontPair = q.front();
            q.pop();
            int x = frontPair.first;
            int y = frontPair.second;
            //explore its nbrs
            for(int k=0; k<4; k++){
                int newX = x + dx[k];
                int newY = y + dy[k];
                if(isSafe(newX, newY, m, n, image, color, originalColor)){
                    //infection successful
                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }
        return image;

    }
};