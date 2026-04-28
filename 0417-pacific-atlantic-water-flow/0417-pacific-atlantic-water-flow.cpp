//bfs
class Solution {
public:
    bool isSafe(int x, int y, const int m, const int n){
        if((x<0 || x>=m)||(y<0 || y>=n)){
            return false;
        }
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int totalNodes = m*n;
        vector<vector<bool>> isVisitedPacific(m, vector<bool>(n, false));
        vector<vector<bool>> isVisitedAtlantic(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        
        queue<pair<pair<int, int>, int>> qPacific; //coordinates, prev Height
        queue<pair<pair<int, int>, int>> qAtlantic; //coordinates, prev Height
        //dont have to traverse through the matix
        //we have our 4 starting areas
        //pacific
        for(int i=0; i<n; i++){
            int x = 0;
            int y = i;
            int parentHeight = heights[x][y];
            qPacific.push({{x, y}, parentHeight});
            //as soon as u push it mark it as visited
            isVisitedPacific[x][y] = true;
        }
        for(int i=0; i<m; i++){
            int x = i;
            int y = 0;
            int parentHeight = heights[x][y];
            qPacific.push({{x, y}, parentHeight});
            //as soon as u push it mark it as visited
            isVisitedPacific[x][y] = true;
        }

        //start the process for pacific
        //explore nbrs
        //up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1}; 
        while(!qPacific.empty()){
            pair<pair<int, int>, int> frontData = qPacific.front();
            qPacific.pop();
            pair<int, int> coordinates = frontData.first;
            int parentHeight = frontData.second;
            int x = coordinates.first;
            int y = coordinates.second;

            //explore its nbrs
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                //check if the new coordinates r safe
                if(isSafe(newX, newY, m, n)){
                    //check if not visited
                    if(isVisitedPacific[newX][newY] == false){
                        //check if flow is correct
                        if(parentHeight <= heights[newX][newY]){
                            //its safe now. u can push it in 
                            qPacific.push({{newX, newY}, heights[newX][newY]});
                            isVisitedPacific[newX][newY] = true;
                        }
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            int x = m-1;
            int y = i;
            int parentHeight = heights[x][y];
            qAtlantic.push({{x, y}, parentHeight});
            //as soon as u push it mark it as visited
            isVisitedAtlantic[x][y] = true;
        }
        for(int i=0; i<m; i++){
            int x = i;
            int y = n-1;
            int parentHeight = heights[x][y];
            qAtlantic.push({{x, y}, parentHeight});
            //as soon as u push it mark it as visited
            isVisitedAtlantic[x][y] = true;
        }

        //start the process for atlantic
        //explore nbrs
        //up, down, left, right
        while(!qAtlantic.empty()){
            pair<pair<int, int>, int> frontData = qAtlantic.front();
            qAtlantic.pop();
            pair<int, int> coordinates = frontData.first;
            int parentHeight = frontData.second;
            int x = coordinates.first;
            int y = coordinates.second;

            //explore its nbrs
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                //check if the new coordinates r safe
                if(isSafe(newX, newY, m, n)){
                    //check if not visited
                    if(isVisitedAtlantic[newX][newY] == false){
                        //check if flow is correct
                        if(parentHeight <= heights[newX][newY]){
                            //its safe now. u can push it in 
                            qAtlantic.push({{newX, newY}, heights[newX][newY]});
                            isVisitedAtlantic[newX][newY] = true;
                        }
                    }
                }
            }
        }

        //ans
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isVisitedPacific[i][j] == true && isVisitedAtlantic[i][j] == true){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};