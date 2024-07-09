class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        //this is like OS only

        int currentTime = 0; // Initialize current time to 0
        long long totalWaitingTime = 0;

        for (auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookingTime = customer[1];

            // If the chef is idle until the customer arrives
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }

            // Calculate the end time for the current customer
            currentTime += cookingTime;
            totalWaitingTime += (currentTime - arrivalTime);
        }   

        // Calculate the average waiting time
        double avgWaitingTime = totalWaitingTime / static_cast<double>(customers.size());
        return avgWaitingTime;
    }
};