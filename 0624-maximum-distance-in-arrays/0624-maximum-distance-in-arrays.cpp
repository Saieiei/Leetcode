class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ////Brute Force Time Limit Exceeded 135 / 136 testcases passed
        //int ans = INT_MIN;
        //int ans1 = 0;
//
        //int n = arrays.size();
//
        //for(int i=0; i<n; i++)
        //{
        //    int localMin = arrays[i][0];
        //    int localMax = arrays[i][arrays[i].size()-1];
//
        //    for(int j=i+1; j<n; j++)
        //    {
        //        int nextLocalMin = arrays[j][0];
        //        int nextLocalMax = arrays[j][arrays[j].size()-1];
//
        //        //now lets try to find out the diff
        //        int diff1 = abs(localMax - nextLocalMin);
        //        int diff2 = abs(nextLocalMax - localMin);
        //        int maxDiff = max(diff1, diff2);
        //        //cout<<"maxDiff "<<maxDiff<<endl;
        //        ans = max(ans, maxDiff);
        //    }
        //}
        //return ans;

        //Initialize the minimum and maximum values with the first array's elements
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int maxDiff = 0;
        
        // Iterate over the arrays starting from the second one
        for (int i = 1; i < arrays.size(); i++) {
            int localMin = arrays[i][0];
            int localMax = arrays[i].back();
            
            // Calculate the possible maximum differences using the current array
            maxDiff = max(maxDiff, abs(localMax - globalMin));
            maxDiff = max(maxDiff, abs(globalMax - localMin));
            
            // Update the global minimum and maximum
            globalMin = min(globalMin, localMin);
            globalMax = max(globalMax, localMax);
        }
        
        return maxDiff;
    }
};