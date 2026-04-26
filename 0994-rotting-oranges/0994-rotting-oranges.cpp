//BFS
//not dijistra algo
auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
};
class Solution {
public:
    bool isSafe(const int newX, const int newY, const int m, const int n, vector<vector<int>>& grid){
        if((newX<0 || newX>=m)||(newY<0 || newY>=n)||(grid[newX][newY] != 1)){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //create q and push all initial 2s
        //with BFS it is guarenteed that 
        //we will get the shortest possible time
        queue<pair<pair<int, int>, int>> q; //pair<coordinates, time>
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    //we dont have to mark anything as visited
                    //because of in-place optimization
                }
            }
        }
        //we need this to explore nbrs
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        //we need to to track the ans
        int maxTimeAns = 0;
        //start the BFS process
        while(!q.empty()){
            pair<pair<int, int>, int> frontData = q.front();
            q.pop();
            pair<int, int> coordinates = frontData.first;
            int currentTime = frontData.second;
            int x = coordinates.first;
            int y = coordinates.second;
            //explore its nbrs
            for(int k=0; k<4; k++){
                int newX = x + dx[k];
                int newY = y + dy[k];
                //check if safe
                if(isSafe(newX, newY, m, n, grid)){
                    //if not visisted
                    if(grid[newX][newY] != 2){
                        //affect it and push it 
                        q.push({{newX, newY}, currentTime + 1});
                        grid[newX][newY] = 2;
                        maxTimeAns = max(maxTimeAns, currentTime + 1);
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //if any fresh oranges found
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return maxTimeAns;
    }
};