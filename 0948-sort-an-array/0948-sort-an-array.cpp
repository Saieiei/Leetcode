class Solution {
public:
//we will do imple merge ort, which will be done baed on recurssion

    void merge(vector<int> &nums, vector<int> &temp, int start, int mid, int end)
    {
        //we will try to connect the 2 arrays
        int i=start, j=mid+1; //this is for nums
        int k=start; //this is for temp array

        //now lets do sorting
        while(i<=mid && j<=end)
        {
            if(nums[i]<=nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }

        //now incase some array is still remaining
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=end) temp[k++]=nums[j++];
        
        //now lets copy the sorted array to the original array
        for (int l = start; l <= end; l++) {
            nums[l] = temp[l]; 
        }
    }

    void mergesort(vector<int> &nums, vector<int> &temp, int start, int end)
    {
        //base case
        if(start>=end) return;
        //calculation
        int mid=start+((end-start)>>1);
        //recursion
        mergesort(nums, temp, start, mid);
        mergesort(nums, temp, mid+1, end);
        //DnC
        merge(nums, temp, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(), 0); //this is the vector where we will store the sorted array
        mergesort(nums, temp, 0, nums.size()-1);
        return nums;
    }
};