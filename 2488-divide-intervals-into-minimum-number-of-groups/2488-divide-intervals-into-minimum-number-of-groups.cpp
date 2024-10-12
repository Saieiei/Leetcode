class Solution {
    //https://www.youtube.com/watch?v=lIzI8PknW6M
    //SLA, swep Line Algorithm, tellls u how many number of event are active at the given point of time
public:
int minGroups(vector<vector<int>>& intervals) {
    //all we have to take care is that, how many number of event are active at a given time
    //these many number of events are not possible together
    //dont tryt o sit and solve it in layman order
    //sla -> starting interval +1, ending interval -1
    //find the prefix sum to get maximum overall for any point of time
    // Vector to store events: (time, type). 
    // Type = 1 for start of an interval, -1 for the end of an interval.
    vector<pair<int, int>> events;
    
    for (auto& interval : intervals) {
        // Start of an interval
        events.push_back({interval[0], 1});
        // End of an interval (we add +1 to the end to mark the end of the inclusive interval), because of the overall 5,5
        events.push_back({interval[1] + 1, -1});
    }
    
    // Sort events by time, if two events have the same time, end event comes first
    sort(events.begin(), events.end());

    int maxGroups = 0;  // To store the result
    int currentGroups = 0;  // To track the number of active groups at any point

    // Traverse through all events
    for (auto& event : events) {
        currentGroups += event.second;  // Add 1 for start, subtract 1 for end
        maxGroups = max(maxGroups, currentGroups);  // Track the maximum number of active groups
    }

    return maxGroups;
}
};