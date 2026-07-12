class Solution {
public:
    int minutesCreater(const string& timePoint){
        int totalMinutes = 0;
        //u can use stoi() if u want
        int hours = (timePoint[0] - '0') * 10 + (timePoint[1] - '0');
        int minutes = (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
        totalMinutes = hours*60 + minutes;
        return totalMinutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        const int totalMin = 1440;
        //M1 - brute force
        //compare each time with each other
        //and compare the roudabout time as well.
        //N^2
        //point to remember that the total mins in a day is 1440
        //1st convert all of timePoints into min ans save it in a vector
        vector<int> minutes;
        for(const string& timePoint: timePoints){
            int mintue = minutesCreater(timePoint);
            minutes.push_back(mintue);
        }
        //bc, optimization/pegion hole principle
        if(minutes.size() > 1440){
            //not possible, we only have 1440 min in a day
            return 0;
        }
        int ans = 1440;
        //now we have to compare each min to each other min 
        //and also find out its roundtime
        for(int i = 0; i < minutes.size()-1; i++){
            //find the roundtime
            for(int j = i+1; j < minutes.size(); j++){
                int diff = abs(minutes[i] - minutes[j]);
                int roundTime = 1440 - diff;
                int minTime = min(diff, roundTime);
                ans = min(ans, minTime);
            }
        }
        return ans;
    }
};