class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n, 0);
        //this game is based on average
        //1st we will find the sum to be found
        
        int sum = 0;
        for(int num: rolls)
        {
            sum = sum + num;
        }
        //now we will find the actual sum of the missing elements
        sum = mean*(rolls.size() + n) - sum;

        //now we have to find out n different elemtns
        //this can be done by finding the avg
        int avg = sum / n;
        int rem = sum % n;

        for(int i=0; i<n; i++)
        {
            ans[i]=avg;
            if(ans[i] < 0 || ans[i] >= 7)
            {
                ans.clear();
                return ans;
            }
        }

        int index = 0;
        while(rem>0)
        {
            ans[index%n]++;
            if(ans[index]>6)
            {
                ans.clear();
                return ans;
            }
            rem--;
            index++;
        }

        if(find(ans.begin(), ans.end(), 0) != ans.end())
        {
            ans.clear();
            return ans;
        }

        //if(find(ans.begin(), ans.end(), 7) != ans.end()) //not possible
        //{
        //    vector<int> ans1;
        //    return ans1;
        //}

        //for(int i=0; i<n; i++)
        //{
        //    if(ans[i]>6 || ans[i]<0)
        //    {
        //        //vector<int> ans1;
        //        ans.clear();
        //        return ans;
        //    }
        //}
        //cout<<sum;
        return ans;
    }
};