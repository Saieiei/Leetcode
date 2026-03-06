//the idea is that we will use incoming and outgoing edges
//the node is considered as judge if it n-1 incoming edeges and 0 outgoing edges
//so calc the incoming and outgoing edges for each node (travese through trust)
//traverse through a loop and check for th ejudge condition
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //initialization, u dont have to do all this if ur suing unordered_map<int, int>
        vector<int>incomingEdge(n+1, 0);
        vector<int>outgoingEdge(n+1, 0);

        //find out incoming and outgoing edges of each node
        for(vector<int> directions: trust){
            int u = directions[0];
            int v = directions[1];
            incomingEdge[v]++;
            outgoingEdge[u]++;
        }

        //traverese through each node and find out the judge
        for(int i=1; i<=n; i++){
            if(incomingEdge[i] == n-1 && outgoingEdge[i] == 0){
                return i;
            }
        }

        //else no judge
        return -1;
    }
};