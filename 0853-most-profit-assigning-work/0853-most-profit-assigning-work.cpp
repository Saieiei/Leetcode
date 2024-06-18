class Solution {
public:
//bruteforce
    //int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    //    int ans=0;
    //    for(int i=0;i<worker.size();i++)
    //    {
    //        int w=worker[i];
    //        int index=-1;
    //        int temp=INT_MIN;
    //        for(int j=0;j<difficulty.size();j++)
    //        {
    //            if(difficulty[j]<=w && profit[j]>=temp)
    //            {
    //                temp=profit[j];
    //                index=j;
    //            }
    //        }
    //        if(index==-1) continue;
    //        else ans=ans+profit[index];
    //    }
    //    return ans;
    //}
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        //we will try to connect difficulty with profit and do conditional sorting
        vector<pair<int, int>> job;
        for(int i=0;i<difficulty.size();i++)
        {   
            job.push_back({difficulty[i], profit[i]});
        }
        sort(job.begin(), job.end());

        sort(worker.begin(), worker.end());

        //now we will find the ans;
        //for this we will through the workers array (outside loop) and the job array (inside loop)
        //then find out which 1 will have the highest profit and take that 1
        int ans=0;
        int j=0;
        int max_profit=0;
        for(int i=0;i<worker.size();i++)
        {
            
            //int j=0;
            while(j < job.size() && job[j].first <= worker[i])
            {
                max_profit=max(max_profit, job[j].second);
                j++;
            }
            ans=ans+max_profit;
        }
        return ans;
    }
};