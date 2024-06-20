class Solution {
public:
    //we will solve this using recurssion and backtracking
    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer)
    {
        //base case
        if(ithCustomer==quantity.size()) return true; //going out of bounds

        //calculation
        for(int i=0;i<counts.size();i++)
        {
            if(counts[i]>=quantity[ithCustomer]) //basically the customer is getting more quantity tha required
            {
                counts[i]=counts[i]-quantity[ithCustomer];
               // assign to the next customer
                // RECURSSION
                if(canDistributeHelper(counts, quantity, ithCustomer+1)) return true;
                //BACKTRACK
                counts[i]=counts[i]+quantity[ithCustomer];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        //we will count the frequency of the elements in  nums in unordered_map
        unordered_map<int, int> countMap;
        for(auto num:nums) countMap[num]++;

        vector<int> count; //this vector will store the requency of each element of nums
        for(auto it: countMap) count.push_back(it.second);
        sort(quantity.rbegin(), quantity.rend()); //sort in DESC
        return canDistributeHelper(count, quantity, 0);  
    }
};