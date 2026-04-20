//BFS
//so we have to follow a specific order -> topological sorting-BFS
//to detect cycles, we will use TS and return based on number of nodes
//prerequisites 1st, and then the rest
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        //adjList
        vector<vector<int>> adjList(numCourses);
        for(const vector<int>& prerequisit: prerequisites){
            int u = prerequisit[1];
            int v = prerequisit[0];
            //directef
            //u->v
            adjList[u].push_back(v);
            indegrees[v]++;
        }

        //no need to worry if disconnected components
        //indegrees will take care of it
        //while using indegree, we do not need isVisited[]
        queue<int> q;
        //topologocal sorting
        //1st find the indegrees with 0 and push it in the q
        for(int node=0; node<numCourses; node++){
            if(indegrees[node] == 0){
                q.push(node);
            }
        }

        int countNodes = 0;
        //process bfs
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            countNodes++;
            //explore the nbrs
            for(const int& nbrNode: adjList[frontNode]){
                indegrees[nbrNode]--;
                if(indegrees[nbrNode] == 0){
                    q.push(nbrNode);
                }
            }
        }
        return (countNodes == numCourses);
    }
};