//to solve this we will use BFS
//cuz i colour is 0 and another is 1
//To use BFS we have to use queue
//mark the initial node with 0, mark it as visted and save the colour
//use unordered_map<int, int> isVisted, NodeColour
//since it can be discountinuous graph, use a for loop
//only pass through when its not visited
//inside the q while loop, u if the nbr colour is same as the frontNode colour then return false
//if diff colout then we can ignore
//if the nbr is not at all visted, then invert the from frontNode colou and mark it as visted and same teh colour
//if u reach the end just return true
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, bool> isVisted;
        unordered_map<int, int> NodeColour;
        queue<int> q;
        int colour = 0;
        //initial none are coloured (-1)
        for(int i=0; i<n; i++){
            NodeColour[i] = -1;
        }
        //colour 1 = 0, colour 2 = 1
        //discontinuous graph
        for(int i=0; i<n; i++){
            if(!isVisted[i]){
                //initial process
                int src = i;
                isVisted[src] = true;
                NodeColour[src] = colour;
                q.push(src);
                //process its nbrs
                while(!q.empty()){
                    int FrontNode = q.front();
                    q.pop();
                    int frontNodeColour = NodeColour[FrontNode];
                    colour = !frontNodeColour;
                    for(int nbr: graph[FrontNode]){
                        //nbr is not visted
                        if(!isVisted[nbr]){
                            isVisted[nbr] = true;
                            NodeColour[nbr] = colour;
                            q.push(nbr);
                        }
                        else{ //if visted and colour is same, return false
                            if(frontNodeColour == NodeColour[nbr]){
                                return false;
                            }
                            //else //if visted but diff colour, simple ignore
                        }
                    }
                }
            }
        }
        //reached end return true
        return true;
    }
};