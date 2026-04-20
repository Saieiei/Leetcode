//DFS
//thinking it as a cycle detection
//if there is a cycle then we can never complete the courses
class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& isVisited, vector<bool>& isPathVisited, vector<int>& numCoursesOrder){
        //visisted
        isVisited[node] = true;
        isPathVisited[node] = true;
        //explore the nbrs
        for(const int& nbr: adjList[node]){
            if(!isVisited[nbr]){
                if(dfs(nbr, adjList, isVisited, isPathVisited, numCoursesOrder)){
                    //cycle detected
                    return true;
                }
            }
            else{
                if(isPathVisited[nbr]){
                    //cycle detected
                    return true;
                }
            }
        }
        isPathVisited[node] = false;
        numCoursesOrder.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //adjList
        vector<vector<int>> adjList(numCourses);
        for(const vector<int>& prerequisit: prerequisites){
            int u = prerequisit[1];
            int v = prerequisit[0];
            //direcrted
            //u->v
            adjList[u].push_back(v);
        }

        vector<bool> isVisited(numCourses, false);
        vector<bool> isPathVisited(numCourses, false);
        vector<int> numCoursesOrder;
        //disconnected graph
        for(int node = 0; node<numCourses; node++){
            if(!isVisited[node]){
                if(dfs(node, adjList, isVisited, isPathVisited, numCoursesOrder)){
                    //there is a cycle in the graph
                    return {};
                }
            }
        }
        reverse(numCoursesOrder.begin(), numCoursesOrder.end());
        return numCoursesOrder; //no cycle
    }
};