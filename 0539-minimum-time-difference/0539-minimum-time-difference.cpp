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
        //M1 - sorting method
        //compare each time with each other (only adjacent ones)
        //and for roudabout, comparing it with last and 1st is enough
        //NlogN
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
        //sort it 
        sort(minutes.begin(), minutes.end());
        int ans = totalMin;
        int tempMin = totalMin;
        //now we have to compare each min to ajacent
        //and also find out final roundtime
        for(int i = 0; i < minutes.size()-1; i++){
            int timeDiff = minutes[i+1] - minutes[i];
            tempMin = min(tempMin, timeDiff);
        }
        //take it as a formula 1440 + startTime - lastTime
        int roundtime = totalMin + minutes[0] - minutes[minutes.size()-1];
        ans = min(tempMin, roundtime);
        return ans;
    }
};