class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //method 2: using 2 pointers, l(low) and h(high), since it is sorted

        int l=0, h=arr.size()-1;
        while(h-l>=k) //this gives u the required elements range,  that is k 
        {
            if(x-arr[l]>arr[h]-x) // dont put >= sign
//the diffence made by lower elemnt of the sorted array is more, this means the element on the right side(higher element) has a low difference, which means we should not touch the higher element of the array as we need only lower differences element, so we should move the lower element to get more low diference
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        vector<int> ans;
        for(int i=l;i<=h;i++)
        {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};