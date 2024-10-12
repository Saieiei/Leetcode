class Solution {
public:
int minGroups(vector<vector<int>>& intervals) {
    // Vector to store events: (time, type). 
    // Type = 1 for start of an interval, -1 for the end of an interval.
    vector<pair<int, int>> events;
    
    for (auto& interval : intervals) {
        // Start of an interval
        events.push_back({interval[0], 1});
        // End of an interval (we add +1 to the end to mark the end of the inclusive interval)
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