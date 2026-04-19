//dijstras algo - for each node/city
//dijstras algo - min heap
class Solution {
public:

    void dijstras(int src, vector<vector<pair<int, int>>>& adjList, vector<int>& distDijstra){
        distDijstra[src] = 0;
        using p = pair<int, int>;
        //minHeap
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src}); //wt, node

        while(!pq.empty()){
            pair<int, int> frontPair = pq.top();
            pq.pop();
            int NodeWt = frontPair.first;
            int node = frontPair.second;
            //trick
            //u dont have to explore
            if(NodeWt > distDijstra[node]){
                continue;
            }
            else{
                //explore the nbrs
                for(pair<int, int>& nbr: adjList[node]){
                    int nbrWt = nbr.first;
                    int nbrnode = nbr.second;
                    if(NodeWt + nbrWt < distDijstra[nbrnode]){
                        distDijstra[nbrnode] = NodeWt + nbrWt;
                        pq.push({distDijstra[nbrnode], nbrnode});
                    }

                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //adjList
        vector<vector<pair<int, int>>> adjList(n); //u, w, v
        for(vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //bidirection
            //u<->v
            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }

        int SmallestNoOfNbrs = INT_MAX;
        int ansNode = 0;
        //traverse through the entier noeds, 1 by 1
        //dont have to worry of the greatest number
        //because this loop will take care of it
        for(int src=0; src<n; src++){
            vector<int> distDijstra(n, INT_MAX);
            dijstras(src, adjList, distDijstra);

            int noOfThresholdNbrs = 0;
            //find out noOfThresholdNbrs
            //not counting sorce node as the nbr
            for(int index=0; index<n; index++){
                if(index != src){
                    if(distDijstra[index] <= distanceThreshold){
                        noOfThresholdNbrs++;
                    }
                }
            }

            //keep track of min noOfThresholdNbrs
            //also we have to retun the largest node
            if(SmallestNoOfNbrs >= noOfThresholdNbrs){
                SmallestNoOfNbrs = noOfThresholdNbrs;
                ansNode = src;
            }
        }
        return ansNode;
    }
};