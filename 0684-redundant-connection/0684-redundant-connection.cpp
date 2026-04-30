//to identify usless bridges -> kruskals Algo
class Solution {
public:
    void findUnion(int uParent, int vParent, vector<int>& ranks, vector<int>& parents){
        //get ranks
        int uRank = ranks[uParent];
        int vRank = ranks[vParent];
        //update
        if(uRank >= vRank){
            ranks[uParent]++;
            parents[vParent] = uParent;
        }
        else{
            ranks[vParent]++;
            parents[uParent] = vParent;
        }
    }
    int findParent(int node, vector<int>& parents ){
        //return if self parents
        if(parents[node] == node){
            return node;
        }
        //else do path compression
        return parents[node] = findParent(parents[node], parents);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //there is no wts in this, so we dont have to sort 1st

        //trackers
        vector<int> parents(n + 1);
        vector<int> ranks(n + 1, 0); //not -1;
        //self parents at the begining
        for(int i=0; i<n; i++){
            parents[i] = i;
        }
        //vector<int> ans;

        //traverse through the edges
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];

            //find the parents
            int uParent = findParent(u, parents);
            int vParent = findParent(v, parents);

            //only process those whos parents r diff
            //the rest is a redundant connection
            if(uParent != vParent){
                //process findUnion
                findUnion(uParent, vParent, ranks, parents);
                //dont have to process anything about wts
            }
            else{
                return {u, v};
            }
        }
        return {};
    }
};