class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //    vector<int> indxs; 
    //    int i=0, j = nums.size()-1;
//
    //    while(i<j && j>=0){
    //            
    //            if(nums[i]+nums[j]==target){
    //                indxs.push_back(i);
    //                indxs.push_back(j);
    //                break;
    //            }
    //            else{
    //                i++;
    //            }
    //            
    //            if(i==j){
    //            i=0;
    //            j--;
    //        }
    //        
    //    }
//
    //    return indxs;  
    //}

    //we will solve this using hashmap
    //1st we will put all the elements in the index order only
    //next we will see if its complement is there in the hashmap
    //if its not there then simply push
    //if its there then, return the values
    //the values r nothing but the indexes of the nums

        unordered_map<int, int> mp;  // Create a hashmap to store the value and its index
        vector<int> ans;             // Vector to store the answer (optional, not used here)

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];  // Calculate the complement of the current element
            if(mp.find(complement) != mp.end()) // Check if the complement exists in the hashmap
                return {i, mp[complement]};     // If found, return the current index and the index of the complement
            else
                mp[nums[i]] = i;  // Otherwise, add the current element and its index to the hashmap
        }
        return {};
    }
};