class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //set approach didnt work
        //set<int>st;
        //vector<int>ans;
        //int n=nums.size();
        //for(int i=0;i<n;i++)
        //{
        //    st.insert(i);
        //}
        //int count=0;
        //for(auto i: st)
        //{
        //    count++;
        //}
        ////for(auto i: st)
        ////{
        ////    ans.push_back(i);
        ////}
        ////int rem=n-count;
        ////for(int i=0;i<rem;i++)
        ////{
        ////    ans.push_back("_");
        ////}
        ////nums=ans;
        //return count;

        //2 pointers approach
        //elements before j are all unique elemnts, j converts the lements to a unique element

        int j=0;
        int i=1;

        while(i<nums.size())
        {
            if(nums[j]==nums[i]) //not unique
            {
                i++;
            }
            else
            {
                j++;
                nums[j]=nums[i];
                i++;
            }

        }
        return j+1;

    }
};