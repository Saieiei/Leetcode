//https://leetcode.com/problems/course-schedule/
//so we have to follow a specific order -> topological sorting-BFS
//to detect cycles, we will use TS and return based on number of nodes
class Solution {
public:
    void topoSortHelper(int& numCourses, unordered_map<int, list<int>>& adjList, vector<int>& topoSort){
        //calculate indegrees
        vector<int> indegrees(numCourses, 0);
        for(pair<const int, list<int>> a: adjList){
            int node = a.first; //nbrs = a.second
            for(int nbr: a.second){
                indegrees[nbr]++;
            }
        }

        //now push 0 indegrees node in the queue
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegrees[i] == 0) q.push(i);
        }

        //keep doing this in q
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            topoSort.push_back(frontNode);
            //update the indegrees
            for(int nbr: adjList[frontNode]){
                indegrees[nbr]--;
                if(indegrees[nbr] == 0) q.push(nbr);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //create adjList
        unordered_map<int, list<int>> adjList;
        for(vector<int> i: prerequisites){
            int u = i[0];
            int v = i[1];
            //according to the q
            adjList[v].push_back(u);
            //u can calculate ur indegrees here is u want to => v->u
        }
        vector<int> topoSort;
        topoSortHelper(numCourses, adjList, topoSort);
        ////detect cycle logic
        //if(topoSort.size() == numCourses) return true;
        //return false;
        return topoSort;
    }
};