//there is a cycle anyways -> topological sorting
//and per 1 disconnected graph, there might be 1 cycle
//because it says that there is only atmost 1 outgoing edge
//so we dont have to create adjList because given data is enough
//BFS
//We will 1st do normal BFS and execute all the nodes thats not in cycle
//the rest of the nodes, thats not visited are basicially cycles of the disconnected graph
//so we will have to travese through of these loops, keep the track of the largest size
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> isVisited(n, false);
        int ans = -1;
        int currLen = 0;
        //process indegrees
        vector<int> indegrees(n, 0);
        for(int i=0; i<n; i++){
            int node = i;
            //explore its nbrs
            int nbr = edges[node];
            //imp
            if(nbr != -1){
                indegrees[nbr]++;
            }
        }

        //BFS
        queue<int> q;
        for(int i=0; i<n; i++){
            //pushin nodes with 0 indegrees
            //and mark it as visited
            int node = i;
            if(indegrees[node] == 0){
                q.push(node);
                isVisited[node] = true;
            }
        }
        //start the process
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            //explore its nbrs
            int nbr = edges[frontNode];
            //very imp
            if(nbr != -1){
                if(!isVisited[nbr]){
                    indegrees[nbr]--;
                    if(indegrees[nbr] == 0){
                        q.push(nbr);
                        isVisited[nbr] = true;
                    }
                }
            }
        }
        //q is empty
        //now all that we have not visited are the cycles
        for(int i=0; i<n; i++){
            int node = i;
            if(!isVisited[node]){
                //cycle discovered
                q.push(node);
                isVisited[node] = true;

                currLen = 0;
                while(!q.empty()){
                    int frontNode = q.front();
                    q.pop();
                    currLen++;
                    //explore nbrs
                    int nbr = edges[frontNode];
                    // Just follow the cycle, no indegree checks needed here
                    if(nbr != -1){
                        if(!isVisited[nbr]){
                            q.push(nbr);
                            isVisited[nbr] = true;
                        }
                    }
                }
                ans = max(ans, currLen);
            }
        }
        return ans;
    }
};