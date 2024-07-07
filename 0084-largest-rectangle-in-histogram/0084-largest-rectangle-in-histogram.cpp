class Solution {
public:
vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            if (st.top() == -1)
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // prev Smaller
    vector<int> prevSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1)return heights[0];
        vector<int>  leftToRight=prevSmaller(heights,n);
        vector<int> rightToLeft=nextSmaller(heights,n);
        // rev krdo
        // reverse(rightToLeft.begin(),rightToLeft.end());
        vector<int>area(leftToRight.size());
        for(int i=0;i<leftToRight.size();i++){
            int width=rightToLeft[i]-leftToRight[i]-1;
            int length=heights[i];
            area[i]=width*length;
        }
        int maxi=INT_MIN;
        for(int i=0;i<area.size();i++){
            maxi=max(maxi,area[i]);
        }
        return maxi;
    }
};