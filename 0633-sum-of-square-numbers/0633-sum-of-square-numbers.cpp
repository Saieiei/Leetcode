class Solution {
public:
    bool judgeSquareSum(int c) {

       ////bruteforce approach
       //long long sqrtc=sqrt(c);
       //vector<long long> arr;
       //arr.push_back(0);
       //for(int i=0;i<sqrtc;i++)
       //{
       //    long long num=i+1;
       //    arr.push_back(num*num);
       //}

       //for(int i=0;i<arr.size();i++)
       //{
       //    for(int j=0;j<arr.size();j++)
       //    {
       //        if(arr[i]+arr[j]==c)
       //        {
       //            return true;
       //        }
       //    }
       //}
       //return false;


       //two sum approach
        long long sqrtc=sqrt(c);
        vector<long long> arr;
        arr.push_back(0);
        for(int i=0;i<sqrtc;i++)
        {
            long long num=i+1;
            arr.push_back(num*num);
        }

        int pointer1=0;
        int pointer2=arr.size()-1;
        //cout<<arr[pointer2];
        //cout<<arr[pointer1];
        while(pointer1<=pointer2)
        {
            long long sum=arr[pointer1]+arr[pointer2];
            if(sum==c) return true;
            if(sum<c) pointer1++;
            if(sum>c) pointer2--;
        }
        return false;
    }
};