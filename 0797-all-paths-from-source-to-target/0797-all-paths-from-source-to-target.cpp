//bfs
//not normal, u have to push in the whole path 
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        //no disconnected graph
        //no edge cases
        queue<vector<int>>q;
        q.push({0});
        vector<vector<int>> ans;

        while(!q.empty()){
            vector<int> currentPath = q.front();
            q.pop();
            int lastNode = currentPath.back();

            //check if we have rached the destination
            int destination = n-1;
            if(lastNode == destination){
                //push it in the ans
                ans.push_back(currentPath);
            }
            else{
                //explore the nbrs
                for(int nbr: graph[lastNode]){
                    vector<int> newPath = currentPath;
                    newPath.push_back(nbr);
                    q.push(newPath);
                }
            }
        }
        return ans;
    }
};