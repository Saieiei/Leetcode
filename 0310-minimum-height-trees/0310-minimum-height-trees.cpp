//we have to do topological sorting
//even though it is undirected, we will consider it as bydirectional
//any leaf node is a node which has indegree[] == 1
auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //bc
        //if only 1 node then return 0
        if(n == 1){
            return {0};
        }
        //if only 2 nodes, then return both the nodes
        //order doesnt matter
        if(n == 2){
            return {edges[0][0], edges[0][1]};
        }

        //create the adjList as it is given as edges
        //and also update the indegrees
        vector<vector<int>> adjList(n);
        vector<int> indegrees(n, 0);
        for(const vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            //bidirectional
            //u<->v
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            indegrees[u]++;
            indegrees[v]++;
        }

        queue<int>q;
        //push the leaf nodes
        for(int i=0; i<n; i++){
            if(indegrees[i] == 1){
                q.push(i);
            }
        }

        //start tthe process
        //in the q only 2 nodes should remain
        while(n > 2){
            int leaNodes = q.size();
            n = n - leaNodes;
            //eliminate all the leaf node
            for(int i=0; i<leaNodes; i++){
                int frontNode = q.front();
                q.pop();
                //explore its nbrs
                for(int nbr: adjList[frontNode]){
                    indegrees[nbr]--;
                    if(indegrees[nbr] == 1){
                        q.push(nbr);
                    }
                }
            }
        }

        vector<int> ans;
        //push what ever is present in the q
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
        }
        return ans;
    }
};