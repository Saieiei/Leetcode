class Solution {
public:
//https://www.youtube.com/watch?v=fsqo6zjFtf0&t=728s
    int numTeams(vector<int>& rating) {
        //thiss is simply simple maths
        //brute force is O(n^3)
        //but this maths trick will do it in O(n^2)

        int ans = 0;
        int n = rating.size();
        //we will find the middle elements 1st
        for(int mid=1; mid<n-1; mid++)
        {
            int leftSmallerCount = 0;
            int rightLargerCount = 0;
            //lets find the number of leftSmallerCount from the mid
            for(int i=0; i<mid; i++)
            {
                if(rating[i] < rating[mid]) leftSmallerCount++;
            }
            //lets find the number of rightLargerCount from the mid
            for(int i=mid+1; i<n; i++)
            {
                if(rating[i] > rating[mid]) rightLargerCount++;
            }
            //increasing order for the mid element
            ans = ans + leftSmallerCount * rightLargerCount;

            //now lets do it for the decreasing order
            int leftLargerCount = 0;
            int rightSmallerCount = 0;
            //lets find the number of leftLargerElement from the mid (maths)
            leftLargerCount = mid - leftSmallerCount;
            rightSmallerCount = n - mid - 1 - rightLargerCount;
            //decreasing order for the mid element
            ans = ans + leftLargerCount * rightSmallerCount;
        }
        return ans;
    }
};