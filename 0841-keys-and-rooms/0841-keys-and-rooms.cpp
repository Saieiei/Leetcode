//The idea about this is traversal
//if u have the adjList and then u do travesal
//and u do a DFS traversal (q, isVisited, countIsVisisted)
//based on countIsVisisted u can tell if u can vist all the rooms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //in this case we dont have to create AdjList
        //but if u want to create a adjList
        unordered_map<int, vector<int>> adjList;
        int n = rooms.size();
        for(int i=0; i<n; i++){
            for(int j = 0; j<rooms[i].size(); j++){
                adjList[i].push_back(rooms[i][j]);
            }
        }

        unordered_map<int, bool> isVisited;
        int countIsVisisted = 0;
        queue<int> q;
        int src = 0;

        //start the dfs process
        q.push(src);
        isVisited[src] = true;
        countIsVisisted++;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            //process its nbrs
            for(int nbr: adjList[frontNode]){
                if(!isVisited[nbr]){
                    q.push(nbr);
                    isVisited[nbr] = true;
                    countIsVisisted++;
                }
            }
        }

        //check
        if(countIsVisisted == rooms.size()){
            return true;
        }
        else{
            return false;
        }

    }
};