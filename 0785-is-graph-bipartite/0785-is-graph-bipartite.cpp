//bfs
//2 colors
//space optimized
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //no need for adjList
        //given data is sufficeint

        //trackers
        //vector<bool> isVisited(n, false);
        //we will use colors[] as trackers itself
        vector<int> colors(n, -1);
        //-1 indicated no color yet
        //0 is red and 1 is blue
        //!color will change it
        //we will start with red
        int color = 0;

        //since its disconnected graph, we need a for loop
        for(int i=0; i<n; i++){
            //process those only if not visited
            int node = i;
            if(colors[node] == -1){
                //start with bfs
                queue<int> q;
                q.push(node);
                //mark it as visited
                //give it the color
                colors[node] = color;

                //start the process
                while(!q.empty()){
                    int frontNode = q.front();
                    q.pop();
                    int frontColor = colors[frontNode];
                    //explore its nbrs if not visited
                    for(int nbr: graph[frontNode]){
                        if(colors[nbr] == -1){
                            //give the color, mark it as visited
                            //and push it
                            int newColor = !frontColor;
                            colors[nbr] = newColor;
                            q.push(nbr);
                        }
                        else{ //colored, either 1 or 0
                            //if already visited then color should not be the same
                            int nbrColor = colors[nbr];
                            if(nbrColor == frontColor){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        //no cases of false, then return true
        return true;
    }
};