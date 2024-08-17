//class Solution {
//public:
//    long long maxPoints(vector<vector<int>>& points) {
//        //Wrong Answer
//        //79 / 157 testcases passed
//        //points = [[0,3,0,4,2],[5,4,2,4,1],[5,0,0,5,1],[2,0,1,0,3]]
//        int sum1 = 0;
//        int sum2 = 0;
//        int row = 0;
//        vector<vector<int>>coordinates;
//
//        for(auto& vec: points)
//        {
//            int col = 0;
//            int maxElement = *max_element(vec.begin(), vec.end());
//            cout<<"maxElement "<< maxElement<<endl;
//            sum1 = sum1 + maxElement;
//            cout<<"sum1 "<<sum1<<endl;
//            while(1)
//            {
//                if(vec[col] == maxElement)
//                {
//                    vector<int> temp;
//                    temp.push_back(row);
//                    temp.push_back(col);
//                    cout<<"maxElement coordinates "<<row<<" "<<col<<endl;
//                    coordinates.push_back(temp);
//                    break;
//                }
//                col++;
//            }
//            row++;
//        }
//
//        int n = coordinates.size();
//        for(int i=0; i<n-1; i++)
//        {
//            int temp = abs(coordinates[i][1] - coordinates[i+1][1]);
//            sum2 = sum2 + temp;
//        }
//        return sum1 - sum2;
//    }
//};
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<long long> dp(n, 0);  // Initialize DP array for row 0

        // Initialize dp with the first row of points
        for(int c = 0; c < n; ++c) {
            dp[c] = points[0][c];
        }

        // Fill dp array row by row
        for(int r = 1; r < m; ++r) {
            vector<long long> new_dp(n, 0);
            vector<long long> left_max(n, 0), right_max(n, 0);
            
            // Compute left_max array
            left_max[0] = dp[0];
            for(int c = 1; c < n; ++c) {
                left_max[c] = max(left_max[c-1], dp[c] + c);
            }
            
            // Compute right_max array
            right_max[n-1] = dp[n-1] - (n-1);
            for(int c = n-2; c >= 0; --c) {
                right_max[c] = max(right_max[c+1], dp[c] - c);
            }

            // Update new_dp with the maximum possible points for each column
            for(int c = 0; c < n; ++c) {
                new_dp[c] = points[r][c] + max(left_max[c] - c, right_max[c] + c);
            }

            dp = new_dp;  // Move to the next row
        }

        // The answer will be the maximum value in the last row of dp array
        return *max_element(dp.begin(), dp.end());
    }
};