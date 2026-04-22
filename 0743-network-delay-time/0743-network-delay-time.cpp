//normal dijstars algo
//set st
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //remember, it starts from 1 and not 0
        //so we have to increase teh size of adjList
        vector<vector<pair<int, int>>> adjList(n+1);
        for(vector<int>& time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            //directional
            //u->v
            adjList[u].push_back({w, v});
        }

        //remember, it starts from 1 and not 0
        //so we have to increase teh size of dist
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;
        dist[k] = 0;
        st.insert({0, k});

        while(!st.empty()){
            pair<int, int> pairValues = *st.begin();
            st.erase(st.begin());
            int nodeWt = pairValues.first;
            int node = pairValues.second;

            //explore nbrs
            for(pair<int, int> nbr: adjList[node]){
                int nbrWt = nbr.first;
                int nbrNode = nbr.second;
                if(nbrWt + nodeWt < dist[nbrNode]){
                    //update the dist[nbrNode]
                    //push the updated pair in the set
                    //tricky
                    //find if that pair is there in the set
                    //if so delete it
                    if(dist[nbrNode] != INT_MAX){
                        st.erase({dist[nbrNode], nbrNode});
                    }
                    dist[nbrNode] = nbrWt + nodeWt;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        int ans = INT_MIN;
        //we will start from 1 directly
        //because 0 is going to be INT_MAX anyways
        //if any of the node is still INT_MAX
        //that means that, it is not able to reach 1 of the nodes
        //if so then return -1;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            else{
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};