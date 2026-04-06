//peeling the onion - indegrees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //bc
        if (n == 1) return {0};

        //create adjList
        unordered_map<int, vector<int>> adjList;
        vector<int> degree(n, 0);
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        //push all the leaf nodes, degree = 1 in the q
        for(int i=0; i<n; i++){ //nodes
            if(degree[i] == 1){
                q.push(i);
            }
        }

        while(n>2){ //either 1 or 2 nodes remaining
            int noLeafNodes = q.size();
            n = n - noLeafNodes; //remainnig nodes
            //process those leaf nodes
            for(int i = 0; i < noLeafNodes; i++){
                int leafNode = q.front();
                q.pop();
                //process its nbrs and their degrees
                for(int nbr: adjList[leafNode]){
                    degree[nbr]--;
                    if(degree[nbr] == 1){ 
                        q.push(nbr);
                        //after the removal of leaf node, 
                        //now this node has become leafNode
                    }
                }
            }
        }

        //push the 1/2 nodes in the ans, which will be in the q
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};