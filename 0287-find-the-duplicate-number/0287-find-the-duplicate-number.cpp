class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //M1 brute force, sort
        //sort(nums.begin(), nums.end());
        //int i = 0;
        //int j = 0;
        //for(int i=0; i<n-1; i++){
        //    j = i+1;
        //    if(nums[i] == nums[j]){
        //        return nums[i];
        //    }
        //}
        ////else
        //return 0;

        //M2 in place, marking - as visisted
        for(int i=0; i<n; i++){
            //marked as visisted
            int index = abs(nums[i]);
            if(nums[index]<0){
                return index;
            }
            else{
                //mark it as visisted
                //mark it -
                //2s compliment
                nums[index] = ~nums[index] + 1;
            }
        }
        return 0;
        
    }
};