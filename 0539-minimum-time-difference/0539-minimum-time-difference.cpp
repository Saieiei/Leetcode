class Solution {
public:

    int Convert_to_minstime(string& time)
    {
        int Total_time=0;
        //1st 2 chars
        int hrs=stoi(time.substr(0, 2));
        hrs=hrs*60;
        //last 2 chars
        int mins=stoi(time.substr(3, 2));
        Total_time=hrs+mins;
        return Total_time;

    }
    int findMinDifference(vector<string>& timePoints) {
        
        //1st we will create a new vector to store the min of each input in timePoints
        //then we will sort it
        //then we will find the min of the difference of each min 
        //then we will also subtract the value from 1st index (1440+timePoints[0] to the last index of timePoints) (reverse)
        //then again we will find the min by including this as well

        vector<int>mins;
        int ans=INT_MAX;
        for(string time:timePoints)
        {
            mins.push_back(Convert_to_minstime(time));
        }
        sort(mins.begin(), mins.end());
        for(int i=0;i<mins.size()-1;i++)
        {
            ans=min(ans, (mins[i+1]-mins[i]));
        }
        //it is obvious that to find out teh reverse time we will have to subtarct the largest time with the smallest time (think of a loop, circle etc)
        int reverseTime=(1440+mins[0])-(mins[mins.size()-1]);
        ans=min(ans, reverseTime);
        return ans;
    }
};