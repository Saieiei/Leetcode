class Solution {
public:
    int mySqrt(int x) {
        //binary search
        //myheart
        //if 1, 0 then simply return
        if(x<2){
            return x;
        }
        int ans = 0;
        int low = 1;
        int high = x/2;
        while(low <= high){ //=
            int mid = low + (high - low)/2;
            if(mid <= x/mid){
                //u got the ans
                //move to the right side
                ans = mid;
                low = mid + 1;
            }
            //but we cant stop
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};