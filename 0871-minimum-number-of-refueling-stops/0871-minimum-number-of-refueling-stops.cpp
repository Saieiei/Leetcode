//we will solve this using priority queue
//the idea is that we will travel as much as possible with the fuel we have and keep storing all the details of the stops
//from that we will pick up the highest fuel stop and update the fuel and dist travelled
//keepdoing until we reached the target or until we ran out of fuel (no stops)
//greedy approach 

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int fuel = startFuel;
        priority_queue<pair<int, int>> pq; //{fuel, dist};
        int i=0; //keeping a ttrack of this 

        while(true){
            while(i<stations.size()){
                if(stations[i][0]<=fuel+dist){
                    pq.push({stations[i][1], stations[i][0]}); //{fuel, dist};
               }
               else break;
               i++;
            }

            //update distance and fuel after this exhausted run
            dist += fuel;
            fuel = 0;

            //check if we have reached since distance has been updated 
            if(dist>=target) break;

            //if we have not reached target yet and there are no stops remaining then break
            if(pq.empty())return -1;
            else{
                pair<int, int> front = pq.top(); pq.pop();
                fuel = front.first + (dist-front.second);
                dist = front.second;
                stops++;
            } 

        }
        return stops;
        
    }
};