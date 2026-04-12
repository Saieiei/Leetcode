//DFS - cycle detetcion
class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<bool>& isVisited, vector<bool>& isPathVisited, vector<int>& dist, int& maxLen, int currLen){
        //mark the node as visisted
        isVisited[node] = true;
        isPathVisited[node] = true;
        currLen += 1;
        dist[node] = currLen;

        //explore the nbr*
        int nextNode = edges[node];
        if(nextNode != -1){
            if(!isVisited[nextNode]){
                dfs(nextNode, edges, isVisited, isPathVisited, dist, maxLen, currLen);
            }
            else if(isPathVisited[nextNode] == true){
                //cycle detetcted -> use formula
                int cycleLen = currLen - dist[nextNode] + 1;
                maxLen = max(maxLen, cycleLen);
            }
        }
        //bt
        isPathVisited[node] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> isVisited(n, false);
        vector<bool> isPathVisited(n, false);
        vector<int> dist(n, 0);
        int maxLen = -1;
        int currLen = -1;

        //disconnectd graph
        for(int i=0; i<n; i++){
            if (!isVisited[i]){
                dfs(i, edges, isVisited, isPathVisited, dist, maxLen, currLen);
            }
        }

        return maxLen;

    }
};