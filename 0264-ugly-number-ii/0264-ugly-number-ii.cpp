class Solution {
public:
    int nthUglyNumber(int n) {
        ////Wrong Answer 102 / 596 testcases passed
        //int ans = 0;
        //int size = 0;
        //vector<int> uglyNum = {1};
//
//
        //for(int i=2; i<=1690; i++)
        //{
        //    if(uglyNum.size() == n)
        //    {
        //        return uglyNum.back();
        //    }
        //    else
        //    {
        //        if(i%2 == 0)
        //        {
        //            if(find(uglyNum.begin(), uglyNum.end(), i/2) != uglyNum.end())
        //            {
        //                uglyNum.push_back(i);
        //                cout<<i<<endl;
        //            }
        //        }
        //        else if(i%3 == 0)
        //        {
        //            if(find(uglyNum.begin(), uglyNum.end(), i/3) != uglyNum.end())
        //            {
        //                uglyNum.push_back(i); cout<<i<<endl;
        //            }
        //        }
        //        else if(i%5 == 0)
        //        {
        //            if(find(uglyNum.begin(), uglyNum.end(), i/5) != uglyNum.end())
        //            {
        //                uglyNum.push_back(i); cout<<i<<endl;
        //            }
        //        }
        //    }
        //}
        //return uglyNum.back();
        
        // Dynamic programming array to store the first n ugly numbers
        vector<int> dp(n);
        dp[0] = 1; // The first ugly number is 1
        
        // Initialize pointers for multiples of 2, 3, and 5
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < n; ++i) {
            // Next multiples of 2, 3, and 5
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;
            
            // The next ugly number is the minimum of the next multiples
            dp[i] = min(next2, min(next3, next5));
            
            // Increment the pointer for the chosen factor(s)
            if (dp[i] == next2) p2++;
            if (dp[i] == next3) p3++;
            if (dp[i] == next5) p5++;
        }
        
        // The nth ugly number is the last element in the dp array
        return dp[n-1];
    }
};