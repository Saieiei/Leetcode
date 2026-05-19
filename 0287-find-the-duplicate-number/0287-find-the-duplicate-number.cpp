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
        //for(int i=0; i<n; i++){
        //    //marked as visisted
        //    int index = abs(nums[i]);
        //    if(nums[index]<0){
        //        return index;
        //    }
        //    else{
        //        //mark it as visisted
        //        //mark it -
        //        //2s compliment
        //        nums[index] = ~nums[index] + 1;
        //    }
        //}
        //return 0;
        
        //M3 0th position
        //while(nums[0] != nums[nums[0]]){
        //    swap(nums[0], nums[nums[0]]);
        //}
        //return nums[0];

        //M4 hashing, freq
        //unordered_map<int, int>mp;
        //for(int i=0; i<n; i++){
        //    //check if the elemnt is already visited
        //    if(mp.count(nums[i])){
        //        //already there
        //        return nums[i];
        //    }
        //    //else mark it as visisted, increasse frew
        //    mp[nums[i]]++;
        //}
        //return 0;

        //M5 binary search
        //we dont care about the value, we will guess based on the index
        int lowIndex = 0;
        int highIndex = n-1; //because 1 is duplicate

        //start the process
        while(lowIndex < highIndex){
            int midIndex = lowIndex + (highIndex - lowIndex)/2;
            int count = 0;

            //find out how many values r less than the midIndex
            for(int i=0; i<n; i++){
                if(nums[i] <= midIndex){
                    count++;
                }
            }
            // If count is greater than mid, duplicate is in the lower half
            if (count > midIndex) {
                highIndex = midIndex;
            } 
            else {
                lowIndex = midIndex + 1;
            }
        }
        return lowIndex; // or return high, they will converge to the duplicate
    }
};