//bfs
auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
class Solution {
public:
    bool isSafe(const int newX, const int newY, const int m, const int n, vector<vector<int>>& output, const int originalColor, map<pair<int, int>, bool>& isVisited){
        if((newX<0 || newX>=m)||(newY<0 || newY>=n)||(isVisited[{newX, newY}])
        ||((output[newX][newY] != originalColor))){
            return false;
        }
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //create isVisited
        int m = image.size();
        int n = image[0].size();
        //we will  create a isVisited
        //no in place optimization
        map<pair<int, int>, bool> isVisited;
        vector<vector<int>>output =  image;
        //create a q
        queue<pair<int, int>> q;
        //1st mark it as visited
        int originalColor; 
        if(image[sr][sc] != color){
            q.push({sr, sc});
            originalColor = image[sr][sc];
            output[sr][sc] = color;
            isVisited[{sr,sc}] = true;
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
                if(isSafe(newX, newY, m, n, output, originalColor, isVisited)){
                    //infection successful
                    output[newX][newY] = color;
                    isVisited[{newX, newY}] = true;
                    q.push({newX, newY});
                }
            }
        }
        return output;

    }
};