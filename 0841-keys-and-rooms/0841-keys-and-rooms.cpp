//traversal
//dfs
class Solution {
public:
    void dfs(int node, vector<bool>& isVisited, vector<vector<int>>& rooms){
        //mark it as visited
        isVisited[node] = true;
        //explore its nbrs
        for(const int& nbr: rooms[node]){
            //check if not visited
            if(isVisited[nbr] == false){
                dfs(nbr, isVisited, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        //no need of adjList cuz rooms is the same

        //trackers
        vector<bool> isVisited(n, false);

        int startNode = 0;
        dfs(startNode, isVisited, rooms);

        //check
        for(int i=0; i<n; i++){
            if(isVisited[i] == false){
                return false;
            }
        }
        //else return true
        return true;
    }
};