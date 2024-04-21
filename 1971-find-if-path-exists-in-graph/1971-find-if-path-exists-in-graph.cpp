//https://www.youtube.com/watch?v=_XGh8YYdx2Q
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //for this concept we will be using queues[q] and a marking scheme[visited] and an adjacency graph[graph]
        queue<int> q;
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        q.push(source);
        visited[source]=true;
        
        //now lets make the ajacency matrix
        for(auto edge:edges)
        {
            //graph[edge[0]]=edge[1];
            //graph[edge[1]]=edge[0];
            //dont do this thsi is wrong because this wont push back other values
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        while(!q.empty())
        {
            vector<int>temp_adjacent=graph[q.front()];
            if(q.front()==destination)
            {
                return true;
            }
            q.pop();
            for(int i=0;i<temp_adjacent.size();i++)
            {
                if(visited[temp_adjacent[i]]==false)
                {
                    q.push(temp_adjacent[i]);
                    visited[temp_adjacent[i]]=true;
                }
            }
        }
        return false;

    }
};