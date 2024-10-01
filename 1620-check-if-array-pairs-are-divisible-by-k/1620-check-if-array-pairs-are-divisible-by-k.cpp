//class Solution {
//public:
//// - numbers 36 / 97 testcases passed
//    bool canArrange(vector<int>& arr, int k) {
//        unordered_map<int, int>mp;
//        int n = arr.size();
//        for(int i=0; i<n; i++)
//        {
//            mp[arr[i]] = 1; //the element is available to be used
//        }
//        int counter = 0;
//        int flagOut = 1;
//        for(int i=0; i<n; i++)
//        {
//            if((abs(k - arr[i]))%k == 0)
//            {
//                counter++;
//                continue;
//            }
//            flagOut = 1;
//            int ele = abs(k - arr[i]);
//            for(auto it = mp.begin(); it!=mp.end(); it++)
//            {
//                if(it->first == ele )
//                {
//                    //it->second = 0;
//                    flagOut = 0;
//                }
//            }
//            if(flagOut == 1) return false;
//        }
//
//        if(counter%2 != 0)//not even pairs then return false
//        {
//            cout<<counter<<endl;
//            return false;
//        }
//        if(flagOut == 1) return false;
//        else return true;
//    }
//};

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) {
                rem += k;
            }
            freq[rem]++;
        }
        
        if (freq[0] % 2 != 0) {
            return false;
        }
        
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};