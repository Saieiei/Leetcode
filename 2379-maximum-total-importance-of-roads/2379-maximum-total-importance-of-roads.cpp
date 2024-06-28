class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //1st we have t find the degree of each node
        //for that we will create a vector of size n and put degree inside it
        vector<long  long> arr(n, 0);

        //now we will find the degree of the nodes
        for(auto i: roads)
        {
            arr[i[0]]++;
            arr[i[1]]++;
        }

        //now we will arrange the degress of the nodes in ascending order
        sort(arr.begin(), arr.end());

        //now we will calculate the final ans
        //since it is in ascending order 
        //the least number of edges(degree) should be given smallest value from 1 to n ie, 1 
        //the largest number of edges(degree) should be given the biggest value from 1 to n ie, n

        long long ans=0;
        long long index=1;
        for(int i=0;i<arr.size();i++)
        {
            ans = ans + (index*arr[i]);
            index++;
        }
        return ans;
    }
};