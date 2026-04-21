//dijstras algo - set
//convert the matrix to adjList
//1D dist[]
class Solution {
public:

    bool isSafe(int newX, int newY, int& m, int &n){
        if((newX < 0 || newX >= m) || (newY < 0 || newY >= n)){
            return false;
        }
        return true;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalNodes = m*n;
        //create adjList
        //since matrix, we have to work with nodeID
        vector<vector<pair<int, int>>> adjList(totalNodes); //we cant say col size for sure 
        //so we will use push_back -> u.push_back(v)

        //helper, down, right
        int dx[] = {1, 0};
        int dy[] = {0, +1};
        //travese through each node
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int nodeID = i*n + j;

                //2 ways
                for(int k=0; k<2; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    //check if safe
                    if(isSafe(newX, newY, m, n)){
                        int nbrNodeID = newX*n + newY;
                        int nbrWt = grid[newX][newY];
                        adjList[nodeID].push_back({nbrWt, nbrNodeID});
                    }
                }
            }
        }

        //dijstra algo
        //set
        set<pair<int, int>> st;
        vector<int>dist(totalNodes, INT_MAX);
        int startNodeID = 0; //i*n+j
        st.insert({grid[0][0], startNodeID});
        dist[startNodeID] = grid[0][0];

        //start the process
        while(!st.empty()){
            pair<int, int> topPair = *st.begin();
            st.erase(st.begin());
            int nodeWt = topPair.first;
            int nodeID = topPair.second;
            //explore the nbrs
            for(pair<int, int> nbr: adjList[nodeID]){
                int nbrWt = nbr.first;
                int nbrNodeID = nbr.second;
                if(nodeWt + nbrWt < dist[nbrNodeID]){
                    //update the dist[nbrNodeID] and push in st
                    //befpre that, if found in st, erase it
                    if(dist[nbrNodeID] != INT_MAX){
                        st.erase({dist[nbrNodeID], nbrNodeID});
                    }
                    dist[nbrNodeID] = nodeWt + nbrWt;
                    st.insert({dist[nbrNodeID], nbrNodeID});
                }
            }
        }
        return dist[totalNodes-1];
    }
};