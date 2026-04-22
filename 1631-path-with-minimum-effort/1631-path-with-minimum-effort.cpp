//this is little advanced compared to minimum cost path
//we need to build adjList and then use dijkstras algo - minHeap (foundation)
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
        //create adjList -> matrix(heights)
        vector<vector<pair<int, int>>> adjList(totalNodes);
        //keep track of directions -> up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        //explore each cell
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int uNodeID = i*cols + j;
                //explore the Vs
                //check if the all 4 directions r safe
                for(int k=0; k<4; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    //check if new coordinates r safe
                    if(isSafe(newX, newY, rows, cols)){
                        int vNodeID = newX * cols + newY;
                        int actualWt = abs(heights[i][j] - heights[newX][newY]);
                        adjList[uNodeID].push_back({actualWt, vNodeID});
                    }
                }
            }
        }

        //dijkstra algo - minHeap
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        int startingEffort = 0;
        int startingNodeID = 0; //i*cols+j
        pq.push({startingEffort, startingNodeID});
        vector<int> dist(totalNodes, INT_MAX);
        dist[startingNodeID] = startingEffort;

        //start the process
        while(!pq.empty()){
            pair<int, int> frontPair = pq.top();
            pq.pop();
            int currentEffort = frontPair.first;
            int currentNodeID = frontPair.second;

            //catch, lazy deletion
            if(currentEffort > dist[currentNodeID]){
                continue;
            }

            //explore nbrs
            for(const pair<int, int>& nbr: adjList[currentNodeID]){
                int upcomingEffort = nbr.first;
                int nbrNodeID = nbr.second;
                int actualEffort = max(currentEffort, upcomingEffort);

                if(actualEffort < dist[nbrNodeID]){
                    //update and push
                    dist[nbrNodeID] = actualEffort;
                    pq.push({dist[nbrNodeID], nbrNodeID});
                }
            }
        }
        return dist[totalNodes -1];
    }
};