class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
    vector<pair<int, double>> cars; // pair of position and time to reach target

    // Calculate the time each car takes to reach the target
    for (int i = 0; i < n; ++i) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    // Sort cars based on their starting positions in decreasing order
    sort(cars.rbegin(), cars.rend());

    stack<double> st;

    // Iterate through the sorted cars
    for (int i = 0; i < n; ++i) {
        double time = cars[i].second;
        // If current car's time is greater than the time at the top of the stack,
        // it means current car cannot catch up to the car fleet ahead, thus it forms a new fleet.
        if (st.empty() || time > st.top()) {
            st.push(time);
        }
    }

    return st.size();
    }

};