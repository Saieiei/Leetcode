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
        //M3 - space optimized
        //compare each time with each other (only adjacent ones)
        //and for roudabout, comparing it with last and 1st is enough
        //N
        //point to remember that the total mins in a day is 1440
        //The process of this becomces N is because we are going to use a vector of size 1440
        //and we will make it as if it is sorted
        //so space is constant.
        //1st convert all of timePoints into min ans save it in a vector
        vector<bool> minutesSeen(totalMin, false);
        for(const string& timePoint: timePoints){
            int minute = minutesCreater(timePoint);
            //bc, optimization/pegion hole principle
            if(minute > totalMin){
                //not possible, we only have 1440 min in a day
                return 0;
            }
            //optimizartion
            if(minutesSeen[minute] == true){
                //the time is same, so net diff is 0
                return 0;
            }
            //record it
            minutesSeen[minute] = true;
        }
        //now travel through the minute vector from the begining
        //always campare the 1st and 2nd and keep a track of min
        //and also find out final roundtime (formula)
        //we also need to keep the track of the indexes for the roundtime
        int firstSeenTime = -1, lastSeenTime = -1;
        int time1 = -1, time2 = -1;
        int ans = totalMin;
        for(int i = 0; i < totalMin; i++){
            if(minutesSeen[i] == true){
                if(time1 == -1){
                    firstSeenTime = i;
                    time1 = firstSeenTime;
                    continue;
                    //we dont want the time2 to also have the same value
                }
                //now time1 already has a time
                //now allocate time2 and the find the diff
                //and then make time1 same as minutesSeen[i]
                time2 = i;
                int diff = (time2 - time1);
                ans = min(ans, diff);
                time1 = i;
                //track the last index Seen as well
                lastSeenTime = i;
            }
        }
        //calculate the round about
        int roundabout = totalMin + firstSeenTime - lastSeenTime;
        ans = min(ans, roundabout);
        return ans;
    }
};