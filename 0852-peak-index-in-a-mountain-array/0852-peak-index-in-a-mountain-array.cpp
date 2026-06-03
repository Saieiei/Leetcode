class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        //Binmary search N
        //byheart
        //once we get the mid ele, check if its next ele is big
        //if so shift low to mid+1
        //if not shift high top mid
        //finally return low
        int low = 0;
        int high = n-1;

        while(low < high){ //=
            int mid = low + (high - low)/2;
            int midEle = arr[mid];
            //now check if the next ele to mid is greater than mid
            if(arr[mid]<arr[mid+1]){
                //if so, shit low to mid+1
                low = mid+1;
            }
            else{
                //move high to mid
                high = mid;
            }
        }
        return low;
    }
};