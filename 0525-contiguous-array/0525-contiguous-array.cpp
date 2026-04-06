//brute force
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLengthSubarrya = INT_MIN;
        int start = 0;
        int end = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = 0; //reset
            start = nums[i];
            for(int j = i; j < n; j++){
                end = nums[j];
                if(end == 0){
                    sum += -1;
                }
                else{
                    sum += 1;
                }
                if(sum == 0){
                    int tempLenght = j - i + 1;
                    maxLengthSubarrya = max(maxLengthSubarrya, tempLenght);
                }
            }
        }
        return maxLengthSubarrya;
    }
};