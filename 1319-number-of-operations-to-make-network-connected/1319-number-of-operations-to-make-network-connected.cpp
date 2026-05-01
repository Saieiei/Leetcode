//kruskals algo
//nocc
class Solution {
public:
    int findParent(int node, vector<int>& parents){
        //check if self then return
        if(parents[node] == node){
            return node;
        }
        //else path compression
        return parents[node] = findParent(parents[node], parents);
    }
    void findUnion(vector<int>& parents, vector<int>&ranks, int uParent, int vParent){
        //get the ranks
        int uParentRank = ranks[uParentRank];
        int vParentRank = ranks[vParentRank];

        //now compare
        if(uParentRank >= vParentRank){
            ranks[uParentRank]++;
            parents[vParent] = uParent;
        }
        else{
            ranks[vParentRank]++;
            parents[uParent] = vParent;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //create trackers
        vector<int> ranks(n, 0);
        vector<int> parents(n);
        //self parents
        for(int i=0; i<n; i++){
            parents[i] = i;
        }

        int redundantConnections = 0;

        //start the process
        //traverse though the edgelist
        for(vector<int> connection: connections){
            int u = connection[0];
            int v = connection[1];
            //find their parents
            int uParent = findParent(u, parents);
            int vParent = findParent(v, parents);

            //do the process if not same
            if(uParent != vParent){
                findUnion(parents, ranks, uParent, vParent);
            }
            else{
                //this is a redundant connection
                //we dont have to push u, v
                //just increase count
                redundantConnections++;
            }
        }

        //now we have to find the actual proper connected edges
        //nocc
        int nocc = 0;
        for(int i=0; i<n; i++){
            if(parents[i] == i){
                nocc++;
            }
        }

        //now we have to find the actual required connections
        int actualRequiredConnections = nocc - 1;

        //now based on the extra connections that u have return
        return (redundantConnections >= actualRequiredConnections) ?  actualRequiredConnections : -1;
    }
};