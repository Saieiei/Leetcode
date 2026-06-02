class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //Binary search logMN
        int low = 0;
        int high = m*n-1;
        //start the process
        while(low <= high){
            int mid = low + (high - low)/2;
            //check if this is the target
            int row = mid/n;
            int col = mid%n;
            int midValue = matrix[row][col];
            if(midValue == target){
                return true;
            }
            else{
                if(midValue > target){
                    high = mid -1;
                }
                else{
                    low = mid +1;
                }
            }
        }
        //not possible
        return false;
    }
};