//this is little advanced compared to minimum cost path
//we need to build adjList and then use dijkstras algo - set (foundation)
//our adjList will be diff
//because we r talking about the diff in the heights,
//which will be considered as the current effort
//the dijkstras algo should track the minimum of
//maximum effort in the path
//in general we update dijkstras algo if,
//nodeWt + nbrWt < dist[nbrNode], but in this case
//we will update only when the max effort is changed
//basically keep track of the max effort (alpha)
//the dijstras algo will automatically keep track of minimum <alphas>
class Solution {
public:
    bool isSafe(int newX, int newY, int& rows, int& cols){
        if((newX < 0 || newX >= rows) || (newY < 0 || newY >= cols)){
            return false;
        }
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int totalNodes = rows*cols;

        //create adjList (nodeIDs)
        //to explore nbrs in adjList , up down left right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        //traverse through the matrix
        vector<vector<pair<int, int>>> adjList(totalNodes);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int uNodeID = i*cols + j;
                //explore nbrs of nodeID
                //should not go out of bounds as well
                for(int k=0; k<4; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if(isSafe(newX, newY, rows, cols)){
                        int vNodeID = newX * cols + newY;
                        int diffWt = abs(heights[i][j] - heights[newX][newY]);
                        adjList[uNodeID].push_back({diffWt, vNodeID});
                    }
                }
            }
        }

        //dijkstra algo - set
        set<pair<int, int>> st;
        int startingNodeID = 0; //i*cols+j
        int startingWt = 0; //no jumps made yet
        st.insert({startingWt, startingNodeID});
        vector<int> dist(totalNodes, INT_MAX);
        dist[startingNodeID] = startingWt;

        //start the process
        while(!st.empty()){
            pair<int, int> pairData = *st.begin();
            st.erase(st.begin());
            int currentWt = pairData.first;
            int uNodeID = pairData.second;
            //explore the nbrs
            for(const pair<int, int>& nbr: adjList[uNodeID]){
                int nbrWt = nbr.first;
                int vNodeID = nbr.second;

                //here is the catch
                //the cost of the path will be the max
                //of the abs difference in the jump
                int actualWt = max(currentWt, nbrWt);

                //we have to find the min 
                //of these max jumps routes
                if(dist[vNodeID] > actualWt){
                    //update and push
                    //erase from st
                    if(dist[vNodeID] != INT_MAX){
                        st.erase({dist[vNodeID], vNodeID});
                    }
                    dist[vNodeID] = actualWt;
                    st.insert({dist[vNodeID], vNodeID});
                }
            }
        }

        return dist[totalNodes -1];
    }
};