//https://www.youtube.com/watch?v=CeYBuGXglTE
class Solution {
public:
    int trap(vector<int>& height) {
        //1st we will check the max height from left (pre[])
        //2nd we will check the max height from right (suf[])
        //then we will use the formula to calc the water/col = min(pre[i], suf[i])-height[i]
        vector<int> pre(height.size()), suf(height.size());
        pre[0]=height[0]; suf[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++)
        {
            pre[i]=max(height[i], pre[i-1]);
            suf[height.size()-1-i]=max(height[height.size()-1-i],suf[height.size()-i] );
        }
        int ans=0;
        for(int i=1;i<height.size()-1;i++)
        {
            ans+=min(pre[i], suf[i])-height[i];
        }
        return ans;
    }
};