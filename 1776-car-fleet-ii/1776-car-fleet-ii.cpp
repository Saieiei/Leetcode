class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        //u wont get this intuition nor get the formukla to get the colision time
        vector<double> colTime(cars.size(), -1); //the colision time of the ith car, which we will return

        stack<int> st;
        for (int i = cars.size() - 1; i >= 0; --i) {
            // Check if car ahead of me is slower and i am faster
            while (!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }

            while (!st.empty()) {
                double collisionTime = (double) (cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                if (collisionTime <= colTime[st.top()] || colTime[st.top()] == -1) {
                    colTime[i] = collisionTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return colTime;
    }
};