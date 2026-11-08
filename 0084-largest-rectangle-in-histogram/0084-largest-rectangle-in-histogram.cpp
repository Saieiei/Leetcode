class Solution {
public:

    void solveNextSmall(vector<int>& nextSmall, vector<int>& heights)
    {
        //1st we will insert -1 into the stack
        //then we will traverse from right to left of heights
        //we will keep poping until we get -1 or find a case where heights[i] > s.top
        //and push heights[i] into the stack when heights[i] > s.top and push the i in the nextSmall

        stack<int> s;
        s.push(-1);
        int n = heights.size();

        //from back
        for(int i=n-1; i>=0; i--)
        {
            //keep poping
            while(s.top() != -1 && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            //if we have come here that means that we have either reached -1 or heights[i]>s.top()
            //so we have to push heights[i] in stack and also insert the index in nextSmall
            nextSmall[i] = s.top();
            s.push(i);
        }
    }

    void solvePrevSmall(vector<int>& prevSmall, vector<int>& heights)
    {
        //1st we will insert -1 into the stack
        //then we will traverse from left to right of heights
        //we will keep poping until we get -1 or find a case where heights[i] > s.top
        //and push heights[i] into the stack when heights[i] > s.top and push the i in the prevSmall

        stack<int> s;
        s.push(-1);
        int n = heights.size();

        //from back
        for(int i=0; i<=n-1; i++)
        {
            //keep poping
            while(s.top() != -1 && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            //if we have come here that means that we have either reached -1 or heights[i]>s.top()
            //so we have to push heights[i] in stack and also insert the index in nextSmall
            prevSmall.push_back(s.top());
            s.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        //This aint easy, u need to know how to finf the nextSmall and prevSmall to begin with
        //and over here we will be playing with the index to find out the area, but in the stack we will storing the elements
        // another point to note is that while solving for next small, we start from the end. 
            //so the point being we have to not enter -1 but rather replace it with the size of the heights, after u have found the nextSmall

        //elements, we dont have to revers ethe nextSmall here because we will be using index and placing the ans behind it self for nextSmall
        vector<int> nextSmall(heights.size());
        vector<int> prevSmall;

        solveNextSmall(nextSmall, heights);
        //replace where ever u get -1 with teh size of the heights in nextSmall
        for(int i=0; i<nextSmall.size(); i++)
        {
            if(nextSmall[i] == -1) nextSmall[i] = heights.size();
        }
        solvePrevSmall(prevSmall, heights);

        //now we find the areas of each block
        vector<int> areas;

        for(int i=0; i<heights.size(); i++)
        {
            int left = prevSmall[i];
            int right = nextSmall[i];
            int length = right - left -1;
            int height = heights[i];
            areas.push_back(length*height);
        }

        //find the ans (maxArea)
        int maxArea = INT_MIN;
        for(int i=0; i<areas.size(); i++)
        {
            maxArea = max(maxArea, areas[i]);
        }

        return maxArea;
    }
};