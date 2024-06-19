class Solution {
public:
    ////lets do bruteforce approach but we will get TLE 84/93
    //int minDays(vector<int>& bloomDay, int m, int k) {
    //    //base case
    //    if (m * k > bloomDay.size()) return -1;
    //    //we will create a set which will have all unique days from the bloomDay
    //    set<int> uniqueDays(bloomDay.begin(), bloomDay.end());
    //    //for(int i: bloomDay)
    //    //{
    //    //    uniqueDays.push_back(i);   //this is not how to put in the elements in the set
    //    //}
//
//
    //    //now lets sort set
    //    //sort(set.begin(), set.end());
    //    //no need to sort them, sets are always in sorted order only
//
    //    int consequtiveDays=0;
    //    int bouquetCount=0;
//
    //    //now we will traverse through the bloomDay vector and find out at what least day we will be able to get the ans
    //    //traverse through the set
    //    //for(int i=0;i<uniqueDays.size();i++)
    //    //{
    //    //    int day=uniqueDays[i];       //this is not how u acces the elements in a set
    //    for(int day: uniqueDays)
    //    {
    //        consequtiveDays=0;
    //        bouquetCount=0;
    //        //traverse through the bloomDay vector
    //        for(int j=0;j<bloomDay.size();j++)
    //        {
    //            if(bloomDay[j]<=day)  //checking if consequtive days or not
    //            {
    //                consequtiveDays++;
    //                if(consequtiveDays==k)
    //                {
    //                    bouquetCount++;
    //                    consequtiveDays=0; //reset consequtiveDays to 0 after we get 1 bouquet
    //                }
    //            }
    //            else consequtiveDays=0; //if not consequtive days then put it as 0;
    //            if(bouquetCount==m) return day;
    //        }
    //    }
    //    return -1;
    //}

    
    //now we will put in binarry search approach as it can be calculated in a linear sorted order

    bool binarysearch(vector<int>& bloomDay, int m, int k, int end)
    {
        int consequtiveDays=0;
        int bouquetCount=0;
        //traverse through the bloomDay vector
        for(int j=0;j<bloomDay.size();j++)
        {
            if(bloomDay[j]<=end)  //checking if consequtive days or not
            {
                consequtiveDays++;
                if(consequtiveDays==k)
                {
                    bouquetCount++;
                    consequtiveDays=0; //reset consequtiveDays to 0 after we get 1 bouquet
                }
            }
            else consequtiveDays=0; //if not consequtive days then put it as 0;
            if(bouquetCount==m) return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        //binarry search
        while(start<=end)
        {
            int mid = start+((end-start)>>1);
            if(binarysearch(bloomDay, m, k, mid)) //checking if its in the 1st half
            {
                ans=mid;
                end=mid-1;
            }
            else //checking if its in the 2nd half
            {
                start=mid+1;
            }
        }
        return ans;
    }
};