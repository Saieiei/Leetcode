class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //approach 1
        //N, N
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        //populate the maxHeights in its respective dir
        //left
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        //right
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(height[i], rightMax[i+1]);
        }

        //start the process
        int totalWater = 0;
        for(int i=0; i<n; i++){
            totalWater = totalWater + (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return totalWater;
    }
};