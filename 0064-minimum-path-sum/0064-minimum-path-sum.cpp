//dijstras algo - minHeap
//convert the matrix to adjList
//1D dist[]
class Solution {
public:

    bool isSafe(int newX, int newY, int& m, int& n){
        if((newX<0 || newX>=m) || (newY<0 || newY>=n)){
            return false;
        }
        return true;
    }

    int minPathSum(vector<vector<int>>& grid) {
        //create adjList using nodeIDs -> input given matrix
        int m = grid.size();
        int n = grid[0].size();
        int totalNodes = m*n;
        vector<vector<pair<int, int>>> adjList(totalNodes);
        //dont know of the col size
        //we will do [u].push_back({_, _})

        //move down, right
        int dx[] = {+1, 0};
        int dy[] = {0, +1};

        //travese through the give data
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int uID =  i*n + j;
                
                //edges
                for(int k=0; k<2; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    //check if the new coordinates r safe
                    if(isSafe(newX, newY, m, n)){
                        //nbrID
                        int vID = newX*n + newY;
                        int w = grid[newX][newY];
                        adjList[uID].push_back({w, vID});
                    }
                }
            }
        }

        //dijkstras algo
        //minHeap
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> dist(totalNodes, INT_MAX);
        //no need of isVisited
        int startingNodeID = 0; //i*n + j
        dist[startingNodeID] = grid[0][0];
        pq.push({dist[startingNodeID], startingNodeID});

        //start the process
        while(!pq.empty()){
            pair<int, int> pairData = pq.top();
            pq.pop();
            int w = pairData.first;
            int uID = pairData.second;

            //lazy delete
            if(w > dist[uID]){
                continue;
            }

            //explore the nbrs
            for(const pair<int, int>& nbr: adjList[uID]){
                int nbrW = nbr.first;
                int nbrID = nbr.second;
                if(nbrW + w < dist[nbrID]){
                    //update and push
                    dist[nbrID] = nbrW + w;
                    pq.push({dist[nbrID], nbrID});
                }
            }
        }
        return dist[totalNodes -1];
    }
};