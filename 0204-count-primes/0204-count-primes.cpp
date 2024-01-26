// what we have to do is 1st create an array from 0 to n
// we will makr all those values are true(which means all r prime)
// then we will use the for loop from 2 to n
// we will check if that value is prime or not
// if its prime then we will increement the ans
// then we will make all its multiples as false till we reach n
// in the end return the ans

//class Solution {
//public:
//   int countPrimes(int n) {
//       vector<bool> prime(n, true);
//       int ans=0;
//       //prefdefine values
//       prime[0]=false;
//       prime[1]=false;
//       if(n==1) return ans;
//       for(int i=2;i<n;i++)
//       {
//           if(prime[i])
//           {
//               ans++;
//               int j=2*i;
//               while(j<n) //multiples of i making them as true
//               {
//                   prime[j]=false;
//                   j=j+i;
//               }
//           }
//       }
//       return ans;
//   }
//};
class Solution {
public:
    int countPrimes(int n) {
        if (n==0)
            return 0;
        vector<bool> prime(n, true); // all.
        prime[0] = prime[1] = false;
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
                int j = 2 * i;
                while (j < n) {  //multiples of i making them as true
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return ans;
    }
};