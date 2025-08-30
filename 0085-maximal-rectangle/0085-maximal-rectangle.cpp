//easy AF
//to solve this u should know the the Q "Largest Rectangle in Histogram"
    //to solve Q "Largest Rectangle in Histogram" u should know how to find the next and previuous smallest element of an array, which is done using a stack
//now to solve this q, basically uk how to find out the max area if its a histogram
//so 1st we will convrt this vector<vector<char>> into vector<vector<int>>
//so ur main task is to find out the histogram of each row
    //find out the area, and keep the track of max area and in the end, return it, simple

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
            nextSmall.push_back(s.top());
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
        //make sure to reverse the ans contnet in the nextSmall
        //and over here we will be playing with the index to find out the area, but in the stack we will storing the elements
        // another point to note is that while solving for next small, we start from the end. 
            //so the point being we have to not enter -1 but rather replace it with the size of the heights, after u have found the nextSmall

        //elements
        vector<int> nextSmall;
        vector<int> prevSmall;

        solveNextSmall(nextSmall, heights);
        reverse(nextSmall.begin(), nextSmall.end());
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        //so 1st we will convrt this vector<vector<char>> into vector<vector<int>>
        int n= matrix.size(); int m = matrix[0].size();
        vector<vector<int>>v(n, vector<int>(m));
        for(int i=0; i<n; i++){ //row
            for(int j=0; j<m; j++){ //col
                v[i][j] = matrix[i][j]-'0';
            }
        }

        //great, so now we have to convert each row into a histogram and find and keep the track of the largest area
        int area = largestRectangleArea(v[0]); //we have sent our 1st row and calculated teh largest area in that as a histogram
        //now we have o do the same for the rest, but as we knoe, histogram is something that cant be floating
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]){//if its is 1
                    //then add up with the previous row value
                    v[i][j] =  v[i][j] + v[i-1][j];
                }
                else{ //doesnt exit, 0
                    //reset the value to 0, so no tower
                    v[i][j] = 0;
                }

            }
            //now find te area of this row and keep the track of max
            area = max(area, largestRectangleArea(v[i]));
        }

        //in the end, returm teh max area
        return area;

    }
};