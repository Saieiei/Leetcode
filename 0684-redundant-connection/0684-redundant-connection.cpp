#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findParent(int node, vector<int>& parents){
        if(parents[node] == node){
            return node;
        }
        // Path compression
        return parents[node] = findParent(parents[node], parents);
    }

    void unionSet(int uParent, int vParent, vector<int>& parents, vector<int>& ranks){
        // Only increment rank if both ranks are equal
        if(ranks[uParent] < ranks[vParent]){
            parents[uParent] = vParent;
        }
        else if(ranks[vParent] < ranks[uParent]){
            parents[vParent] = uParent;
        }
        else{
            parents[vParent] = uParent;
            ranks[uParent]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        
        // Size is V + 1 to safely handle 1-based indexing (nodes 1 to V)
        vector<int> parents(V + 1);
        vector<int> ranks(V + 1, 0);
        
        for(int u = 0; u <= V; u++){
            parents[u] = u;
        }

        // Start processing the edges in their original order
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            int uParent = findParent(u, parents);
            int vParent = findParent(v, parents);

            // Process only when the parents are not the same
            if(uParent != vParent){
                unionSet(uParent, vParent, parents, ranks);
            }
            else {
                // If parents are the same, this edge creates a cycle!
                return {u, v}; 
            }
        }
        
        return {}; // Return empty if no cycle is found
    }
};