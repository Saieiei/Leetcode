class Solution {
public:
    int minimumDeletions(string s) {
        //https://www.youtube.com/watch?v=dkaEBlvjxA8
        //this 1 is a bit uninque
        
        //we will have to find out a count
        //we will have to find out b count
        //then we will find the min number elements that needs to be removed

        int n = s.length();
        vector<int> aCount(n, 0);
        vector<int> bCount(n, 0);

        //no ba' s
        //finding b counts left to right
        for(int i=1; i<n; i++)
        {
            char prevChar = s[i-1];
            bCount[i] = bCount[i-1];
            if(prevChar == 'b') bCount[i]++;
        }
        //finding a counts right to left
        for(int i=n-2; i>=0; i--)
        {
            char prevChar = s[i+1];
            aCount[i] = aCount[i+1];
            if(prevChar == 'a') aCount[i]++;
        }

        //minimum deletions
        int minDel = INT_MAX;
        for(int i=0; i<n; i++)
        {
            minDel = min(minDel, (aCount[i] + bCount[i]));
        }
        return minDel;
    }
};