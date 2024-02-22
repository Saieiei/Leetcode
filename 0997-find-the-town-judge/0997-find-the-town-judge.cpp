// the left element trusts some1
// the right element is being trusted by ome1
// so in the array left element can never be the Town Judge
// the right elemtn is consider to the town judge only if all the elements are trusting the right elemt
// https://www.youtube.com/watch?v=ZUP_tIs4VaE
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //int n=trust.size();
        vector<pair<int,int>> arr(n+1, {0,0}); //we will be using pairs of array whose size is n+1 and all r innitialized to [0,0]
        for(int i=0;i<trust.size();i++)
        {
            arr[trust[i][0]].first+=1; //trusting some1
            arr[trust[i][1]].second+=1; //being trusted by some1
        }
        for(int i=1;i<=n;i++) //u dont have to start with 0 as it is always (0,0)
        {
            if(arr[i].first==0 && arr[i].second==n-1) //n-1 because teh town hall cannot trust himself
                return i;
        }
        return -1;

        
    }
};