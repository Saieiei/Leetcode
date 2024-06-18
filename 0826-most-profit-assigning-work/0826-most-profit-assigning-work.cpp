class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        for(int i=0;i<worker.size();i++)
        {
            int w=worker[i];
            int index=-1;
            int temp=INT_MIN;
            for(int j=0;j<difficulty.size();j++)
            {
                if(difficulty[j]<=w && profit[j]>=temp)
                {
                    temp=profit[j];
                    index=j;
                }
            }
            if(index==-1) continue;
            else ans=ans+profit[index];
        }
        return ans;
    }
};