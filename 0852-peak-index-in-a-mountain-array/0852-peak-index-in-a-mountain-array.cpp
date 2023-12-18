class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       //we will use binarry search 
       //10 20 50 60 70 

       //        50
       //     20     60
       // 10             70

       //lets consider 10, 20, 30 as A side
       //lets consider 50, 60, 70 as peak and B side
       //In A side its ascending
       //In B side and peak its decending (club this)
       //using binary search we should land at the peak i.e start=end

       int start=0;
       int end=arr.size()-1;
       int mid=start+(end-start)/2;

       while(start<end) //very imp or else infinite loop only 
       {
           if(arr[mid]<arr[mid+1])
           {
               start=mid+1;
           }
          else
          {
              end=mid;
          }
          mid=start+(end-start)/2;
       }
       return start;


    }
};