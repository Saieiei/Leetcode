class Solution {
public:
    //we will use sliding window concept
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int grumpy_zero=0, maxSlindingWindowValue=0, slidingWindowValue=0;
        for(int i=0;i<customers.size();i++)
        {
            //if the shopkeeper is not grumpy, just simply add the customer values
            if(grumpy[i]==0) grumpy_zero=grumpy_zero+customers[i];
            //now we will create the sliding window 1st
            if(i<minutes) 
            {
                if(grumpy[i]==1) slidingWindowValue=slidingWindowValue+customers[i];
            }
            //we have reached the sliding window, now we r 1 element ahead,
            // so we have add it to grumpy if its 1 and subract the 1st eleemtn o fthe sliding window
            else
            {
                //so we have add it to grumpy if its 1
                if(grumpy[i]==1) slidingWindowValue=slidingWindowValue+customers[i];
                //and subract the 1st eleemtn o fthe sliding window
                if(grumpy[i-minutes]==1) slidingWindowValue=slidingWindowValue-customers[i-minutes];
            }
            maxSlindingWindowValue=max(maxSlindingWindowValue, slidingWindowValue);
        }
        return maxSlindingWindowValue+grumpy_zero;
    }
};