//topological
//BFS 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> isVisited(numCourses, false);
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for(vector<int> prerequisit: prerequisites){
            int u = prerequisit[0];
            int v = prerequisit[1];
            adjList[v].push_back(u);
            indegrees[u]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegrees[i] == 0){
                q.push(i);
                isVisited[i] = true;
            }
        }

        //start the process
        int courseNumber = 0;
        while(!q.empty()){
            int frontNode = q.front();
            courseNumber++;
            q.pop();
            //explore its nbrs
            for(int nbr: adjList[frontNode]){
                if(!isVisited[nbr]){
                    indegrees[nbr]--;
                    if(indegrees[nbr] == 0){
                        q.push(nbr);
                        isVisited[nbr] = true;
                    }
                }
            }
        }

        if(courseNumber == numCourses){
            return true;
        }
        return false;
    }
};