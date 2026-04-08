//normal dijstars algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       //adjList
       //the size is n+1 cuz the numbering is from 1-n
       vector<vector<pair<int, int>>> adjList(n + 1); //u -> w, v
       for(const vector<int> time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            //directed
            adjList[u].push_back({w, v});
        }

       //so 0 will always be INT_MAX
       vector<int> dist(n+1, INT_MAX);

       //minheap-priority_queue //wt, node
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

       dist[k] = 0;
       pq.push({0, k});

       //start processing
       while(!pq.empty()){
            pair<int, int> topPair = pq.top();
            pq.pop();
            int nodeWt = topPair.first;
            int node = topPair.second;
            //process its nbrs
            for(const pair<int, int> nbr: adjList[node]){
                int nbrWt = nbr.first;
                int nbrNode = nbr.second;
                if(nodeWt + nbrWt < dist[nbrNode]){
                    //update the dist[nbrNode] and push in the pq
                    dist[nbrNode] = nodeWt + nbrWt;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        //return the max time from dist[] and ignore 0 index as it is always INT_MAX
        int ansTime = 0;
        for(int i=1; i<=n; i++){
            //if any dist[node] from 1 - n is INT_MAX, then dijstars algo didnt work, so not possible
            if(dist[i] == INT_MAX){
                return -1;
            }
            ansTime = max(ansTime, dist[i]);
        }
        return ansTime;
    }
};