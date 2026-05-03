auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
//follows topo order concept
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //set up trackers. +1 because its starting from 1
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        //we dont need a adjList here for the nbrs
        //traverse through the given data
        for(const vector<int> &data: trust){
            int u = data[0];
            int v = data[1];
            //directed
            //u->v
            indegree[v]++;
            outdegree[u]++;
        }

        //now find the town judge
        //should have no outgoing edges (trusts none)
        //should have n-1 edges (all trusts, except himself)
        for(int i=1; i<=n; i++){
            if(outdegree[i] == 0 && indegree[i] == n-1){
                //found him
                return i;
            }
        }
        //didint find
        return -1;
    }
};