class Solution {
public:
    int countPrimes(int n) {

        if(n < 2){
            return 0;
        }

        vector<int> arr(n, 1);
        
        for(int i = 2; i*i < n ; i++)
        {
            for (int j = i*i; j < n; j+=i)
            {
                arr[j] = 0;
            }
        }

        int prime = 0;

        for (int i = 2; i < n; i++) //we go till 1 number below
        {
            if(arr[i] == 1)
            {
                prime++;
            }
        }

        return prime;
    }
};