//dijstras algo - for each node/city
class Solution {
public:

    vector<int> dijstra(unordered_map<int, vector<pair<int, int>>>& adjList, int src, int n){
        set<pair<int, int>> st; //wt, v
        vector<int> dist(n, INT_MAX);
        st.insert({0, src});
        dist[src] = 0;

        while(!st.empty()){
            pair<int, int> topPair = *st.begin();
            int node = topPair.second;
            int nodeDist = topPair.first;
            st.erase(st.begin());

            //explore nbrs
            for(pair<int, int> nbr: adjList[node]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                if(nodeDist + nbrDist < dist[nbrNode]){
                    //remove it if it present in the set
                    auto it = st.find({nbrDist, nbrNode});
                    if(it != st.end()){ //found it
                        st.erase({dist[nbrNode], nbrNode});
                    }
                    dist[nbrNode] = nodeDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }

            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adjList; //u -> {v, w}
        //set<pair<int, int>> st; //wt, v
        //vector<int> dist(n, INT_MAX);
        int smallestCityNoOfNeighbours = 0;
        int noOfCities = 0;
        int minNoOfCities = INT_MAX;


        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //bidirectional/undirected
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        for(int src = 0; src < n; src++){
            vector<int> dist = dijstra(adjList, src, n);
            noOfCities = 0;

            //find the no of cities possible to be visted under teh threshold
            for(int u=0; u<n; u++){ //dist
                if(src != u && dist[u] <= distanceThreshold){
                    noOfCities++;
                }
            }

            //keeping the track of min possible city
            if(noOfCities <= minNoOfCities){
                minNoOfCities = noOfCities;
                smallestCityNoOfNeighbours = src;
            }
        }
        return smallestCityNoOfNeighbours;
    }
};