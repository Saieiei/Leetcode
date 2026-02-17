#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //build adjacency list
        vector<vector<pair<int, int>>> adjList(n + 1);
        for(auto i: times) {
            //i -> vector<int>
            //i[0] -> u
            //i[1] -> v
            //i[2] -> time
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adjList[u].push_back(make_pair(v, wt));
        }

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P> > pq;
        
        //initial state -> {timesofar, node}
        pq.push({0, k});
        
        int visitedNodeCount = 0;
        unordered_map<int, bool> visited;
        int timeAns = 0;
        
        //main logic
        while(!pq.empty()) {
            pair<int, int> topPair = pq.top();
            pq.pop();
            
            int currTime = topPair.first;
            int currNode = topPair.second;
            
            //bhot important h
            if(visited[currNode] == true) {
                //ignore
                continue;
            }
            
            //if not visited
            visited[currNode] = true;
            visitedNodeCount++;
            timeAns = max(timeAns, currTime);
            
            //process nbrs
            for(pair<int, int> nbr: adjList[currNode]) {
                //nbr.first -> int -> node
                //nbr.second -> int -> time/weight
                if(visited[nbr.first] == false) {
                    pq.push({currTime + nbr.second, nbr.first});
                }
            }
        }
        
        // If we visited all nodes, return the timeAns. Otherwise, return -1.
        if (visitedNodeCount == n) {
            return timeAns;
        } else {
            return -1;
        }
    }
};