class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //approach 2 2 pointer
        //N, 1
        int leftIndex = 0;
        int rightIndex = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int waterCollected = 0;
        //left should not be right
        //if leftht is smaller than right then execute left
        //if the maxHt needs updatign then do that 1st
        //else get the water and it
        //then update the pointers
        while(leftIndex < rightIndex){
            if(height[leftIndex] < height[rightIndex]){
                //execute left
                //check if max needs updating
                if(height[leftIndex] > leftMax){
                    leftMax = height[leftIndex];
                }
                else{
                    //no need of updating, just add the water
                    waterCollected = waterCollected + (leftMax - height[leftIndex]);
                }
                //update the index
                leftIndex++;
            }
            else{
                //execute right
                //check if max needs updating
                if(height[rightIndex] > rightMax){
                    rightMax = height[rightIndex];
                }
                else{
                    //no need of updating, just add the water
                    waterCollected = waterCollected + (rightMax - height[rightIndex]);
                }
                //update the index
                rightIndex--;
            }
        }
        return waterCollected;
    }
};