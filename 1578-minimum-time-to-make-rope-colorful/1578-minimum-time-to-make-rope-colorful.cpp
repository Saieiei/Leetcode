class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        //we will be using 2 pointers approach
        int i=0,j=0;
        //i and j will be pointing on the same colour range
        //i will be pointing to the begining of that range
        //j will be pointintg to the end of that range
        //we will do the sum(neededTime) of the same colour range
        //then subtract the max value of that range to get the final value
        //we will add the final value of each range to get the final answer
        int ans=0;
        while(j<=n)
        {
            if(colors[i]==colors[j])
            {
                j++;
            }
            else
            {
                int sum=0;
                sum=accumulate(neededTime.begin()+i,neededTime.begin()+j,0);
                sum-=*max_element(neededTime.begin()+i,neededTime.begin()+j);
                ans+=sum;
                i=j;
            }
        }
        
        return ans;
    }
};