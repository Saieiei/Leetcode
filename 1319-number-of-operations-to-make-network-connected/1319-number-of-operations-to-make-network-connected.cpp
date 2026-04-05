//kruskals-algo - redundant conn
class Solution {
public:

    int findParent(int node, vector<int>& parents){
        if(parents[node] == node){
            return node;
        }
        //else{ //path compression
            return parents[node] = findParent(parents[node], parents);
        //}
    }

    void unionOperation(int uParent, int vParent, vector<int>& parents, vector<int>& ranks){
        int uRank = ranks[uParent];
        int vRank = ranks[vParent];

        if(uRank > vRank){
            parents[vParent] = uParent;
            ranks[uParent]++;
        }
        else if(vRank > uRank){
            parents[uParent] = vParent;
            ranks[vParent]++;
        }
        else{ //both ranks are the same
            parents[vParent] = uParent;
            ranks[uParent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parents(n);
        vector<int>ranks(n, 0);
        for(int i=0; i<n; i++){
            parents[i]=i;
        }
        int redundantConnections = 0;

        for(vector<int> connection: connections){
            int u = connection[0];
            int v = connection[1];

            int uParent = findParent(u, parents);
            int vParent = findParent(v, parents);

            if(uParent != vParent){
                unionOperation(uParent, vParent, parents, ranks);
            }
            else{//redundant connetion
                redundantConnections++;
            }
        }

        //nocc
        int nocc = 0;
        int noOfRequiredWires = 0;
        for(int i=0; i<n; i++){
            if(parents[i] == i){
                nocc++;
            }
        }
        noOfRequiredWires = nocc - 1;

        return (redundantConnections >= noOfRequiredWires) ? noOfRequiredWires : -1;
    }
};