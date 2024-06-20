class Solution {
public:
    //week8
    //we will solve it using recurssion and backtracking

    void countArrangementHelper(vector<int> &temp, int &n, int &ans, int currNum)
    {
        //base cases
        if(currNum==n+1)
        {
            ans++;
            return;
        }

        //calculations
        for(int i=1;i<=n;i++)
        {
            if(temp[i]==0 && (currNum % i == 0 || i % currNum == 0)) //we will cinsider 0 as empty field
            {
                temp[i]=currNum;
                //RECURSSION
                countArrangementHelper(temp, n, ans, currNum+1);
                //BACKTRACKING
                temp[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        int ans=0;
        vector<int> temp(n+1,0);
        //direct updates will be  done on ans, hence no retun (call by reference)
        countArrangementHelper(temp, n, ans, 1);
        return ans;
        
    }
};