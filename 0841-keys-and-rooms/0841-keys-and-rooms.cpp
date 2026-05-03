//traversal
//BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        //dont have to create adjList because rooms is same
        vector<bool> isVisited(n, false);

        queue<int> q;
        q.push(0);
        isVisited[0] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            //explore its nbrs
            for(const int& nbr: rooms[frontNode]){
                //check if not visitied
                if(isVisited[nbr] == false){
                    //mark it as visited and push it in 
                    q.push(nbr);
                    isVisited[nbr] = true;
                }
            }
        }

        //check if possible
        for(int i=0; i<n; i++){
            if(isVisited[i] == false){
                return false;
            }
        }
        //else possible
        return true;
    }
};